<?php
// =================================================================
// List and CLI Handler Refactored into Single File
// =================================================================
require_once('Electronic.php');
if (session_status() == PHP_SESSION_NONE) { session_start(); }
// session_destroy();

// Session initialization
if (!isset($_SESSION['list'])) { $_SESSION['list'] = []; }
if (!isset($_SESSION['newId'])) { $_SESSION['newId'] = 1; }


if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    header('Content-Type: application/json');
    $data = json_decode(file_get_contents('php://input'), true);
    $response = ["message" => "Command not found!", "refresh" => false, "search" => null];
    
    $newId = &$_SESSION['newId'];
    $list = &$_SESSION['list'];
    $command = $data['command'];

    $parts = explode(' ', $command);
    $cmd = strtoupper($parts[0]);

    switch ($cmd) {
        case 'ADD':
            $addParts = explode('"', $command);
            $addName = trim($addParts[1]);
            $addCategory = trim($addParts[3]);
            $addPrice = intval(trim($addParts[4]));
            $addPhoto = trim($addParts[5]);
            $list[] = new Electronic($newId, $addName, $addCategory, $addPrice, $addPhoto);
            $newId++;
            $response["message"] = 'A new electronic data has been added.';
            $response["refresh"] = true;
            break;

        case 'DELETE':
            $deleteId = intval(trim($parts[1]));
            foreach ($list as $key => $item) {
                if ($item->getId() === $deleteId) {
                    unset($list[$key]);
                    break;
                }
            }
            $response["message"] = "Data with ID $deleteId has been deleted.";
            $response["refresh"] = true;
            break;

        case 'UPDATE':
            $updateParts = explode('"', $command);
            $updateId = intval(trim(explode(' ', $updateParts[0])[1]));
            $updateName = trim($updateParts[1]);
            $updateCategory = trim($updateParts[3]);
            $updatePrice = intval(trim($updateParts[4]));
            $updatePhoto = trim($updateParts[5]);
            $found = false;
            foreach ($list as &$item) {
                if ($item->getId() === $updateId) {
                    $item->setName($updateName);
                    $item->setCategory($updateCategory);
                    $item->setPrice($updatePrice);
                    $item->setPhoto($updatePhoto);
                    $response["message"] = "Data with ID $updateId has been updated.";
                    $response["refresh"] = true;
                    $found = true;
                    break;
                }
            }
            if (!$found) $response["message"] = "Data with ID $updateId not found.";
            break;

        case 'SEARCH':
            $searchParts = explode('"', $command);
            $searchName = trim($searchParts[1]);
            $found = false;
            foreach ($list as $item) {
                if (stripos($item->getName(), $searchName) !== false) {
                    $found = true;
                    $response["search"] = $item->getId();
                    $response["message"] = "Data Found!";
                    $response["refresh"] = true;
                    break; 
                }
            }
            if (!$found) $response["message"] = "Data with name '{$searchName}' not found.";
            break;

        case 'HELP':
            $response["message"] = 'Command available:<br>';
            $response["message"] .= '1. ADD "name" "category" price "photo"<br>';
            $response["message"] .= '2. DELETE ID<br>';
            $response["message"] .= '3. UPDATE ID "name" "category" price "photo"<br>';
            $response["message"] .= '4. SEARCH "name"<br>';
            break;

        default:
            $response["message"] = 'Command not found! Type HELP for available commands.';
    }
    $_SESSION['list'] = $list;
    echo json_encode($response);
    exit; 
}

if (isset($_GET['action']) && $_GET['action'] === 'list') {
    $list = $_SESSION['list'];
    $search = isset($_GET['search']) ? $_GET['search'] : null;
    ?>
    <table class="w-full border-separate" style="border-collapse: collapse;">
        <thead class="bg-gray-200 dark:bg-gray-700 sticky top-0 shadow-md">
            <tr>
                <th class="py-3 px-4 w-[60px] text-right border-b border-gray-300 dark:border-gray-600">ID</th>
                <th class="py-3 px-4 text-left border-b border-gray-300 dark:border-gray-600">Name</th>
                <th class="py-3 px-4 w-[200px] text-left border-b border-gray-300 dark:border-gray-600">Category</th>
                <th class="py-3 px-4 w-[180px] text-right border-b border-gray-300 dark:border-gray-600">Price (Rp)</th>
                <th class="p-2 w-[110px] text-center border-b border-gray-300 dark:border-gray-600">Photo</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($list as $index => $item) { ?>
            <tr class="hover:bg-sky-100 dark:hover:bg-sky-900 transition-colors duration-200 
                       <?php echo $search == $item->getId() ? 'bg-yellow-200 dark:bg-yellow-700' : ''; ?>">
                <td class="py-2 px-4 border-b border-gray-200 dark:border-gray-800 text-right"><?php echo $item->getId(); ?></td>
                <td class="py-2 px-4 border-b border-gray-200 dark:border-gray-800"><?php echo htmlspecialchars($item->getName()); ?></td>
                <td class="py-2 px-4 border-b border-gray-200 dark:border-gray-800"><?php echo htmlspecialchars($item->getCategory()); ?></td>
                <td class="py-2 px-4 border-b border-gray-200 dark:border-gray-800 text-right"><?php echo number_format($item->getPrice()); ?></td>
                <td class="p-2 text-center border-b border-gray-200 dark:border-gray-800">
                    <img src="images/<?php echo htmlspecialchars($item->getPhoto()); ?>" class="w-full h-[65px] object-cover mx-auto rounded-md shadow-sm">
                </td>
            </tr>
            <?php } ?>
        </tbody>
    </table>
    <?php
    exit;
}

// =================================================================
// Main program
// =================================================================
$images = glob('images/*.*', GLOB_BRACE);
?>
<!DOCTYPE html>
<html lang="en">    
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" type="image/png" href="icon.jpg">
    <title>Electronics Shop</title>
    <script src="https://cdn.tailwindcss.com"></script>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@400;500;600;700&display=swap" rel="stylesheet">
    <style>
        :root { --bg-light: #f3f4f6; --text-light: #1f2937; --card-light: #ffffff; --border-light: #e5e7eb; }
        html.dark { --bg-dark: #1f2937; --text-dark: #f9fafb; --card-dark: #374151; --border-dark: #4b5563; }
        body { font-family: 'Poppins', sans-serif; transition: background-color 0.3s, color 0.3s; }
        .theme-light { background-color: var(--bg-light); color: var(--text-light); }
        .theme-dark { background-color: var(--bg-dark); color: var(--text-dark); }
        .card { transition: background-color 0.3s, border-color 0.3s; }
        .theme-light .card { background-color: var(--card-light); border-color: var(--border-light); }
        .theme-dark .card { background-color: var(--card-dark); border-color: var(--border-dark); }
        ::-webkit-scrollbar { width: 8px; }
        ::-webkit-scrollbar-track { background: #f1f1f1; }
        html.dark ::-webkit-scrollbar-track { background: #2d3748; }
        ::-webkit-scrollbar-thumb { background: #888; border-radius: 4px; }
        html.dark ::-webkit-scrollbar-thumb { background: #555; }
        ::-webkit-scrollbar-thumb:hover { background: #555; }
        html.dark ::-webkit-scrollbar-thumb:hover { background: #777; }
    </style>
</head>
<body class="theme-light">
    <nav class="card flex justify-between items-center px-8 h-[10vh] shadow-md sticky top-0 z-20 border-b">
        <h1 class="font-bold text-xl">⚡ Electronics Shop</h1>
        <div class="flex items-center gap-4">
            <button id="theme-toggle" class="focus:outline-none p-2 rounded-full hover:bg-gray-200 dark:hover:bg-gray-600 transition-colors">
                <svg id="theme-icon-light" class="w-6 h-6" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 3v1m0 16v1m8.66-15.66l-.7.7M4.04 19.96l-.7.7M21 12h-1M4 12H3m15.66 8.66l-.7-.7M4.04 4.04l-.7-.7M12 18a6 6 0 100-12 6 6 0 000 12z"></path></svg>
                <svg id="theme-icon-dark" class="w-6 h-6 hidden" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M20.354 15.354A9 9 0 018.646 3.646 9.003 9.003 0 0012 21a9.003 9.003 0 008.354-5.646z"></path></svg>
            </button>
            <button onclick="toggleSidebar()" class="focus:outline-none p-2 rounded-full hover:bg-gray-200 dark:hover:bg-gray-600 transition-colors">
                <svg class="w-6 h-6" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M4 6h16M4 12h16m-7 6h7"></path></svg>
            </button>
        </div>
    </nav>
    <aside class="card fixed right-0 p-6 w-[30%] h-[90vh] transition-transform duration-300 transform translate-x-full z-10 shadow-lg border-l">
      <h2 class="text-lg font-semibold mb-4">Available Images</h2>
        <div class="grid grid-cols-3 gap-4 overflow-y-auto h-[calc(100%-40px)]">
            <?php foreach ($images as $item) { ?>
            <div class="flex flex-col items-center">
                <img src="<?php echo $item; ?>" class="w-full h-auto object-cover rounded-lg mb-1 shadow">
                <h3 class="text-xs font-semibold break-all text-center"><?php echo basename($item); ?></h3>
            </div>
            <?php } ?>
        </div>
    </aside>
    <main class="w-full flex h-[90vh] justify-between container mx-auto p-8 gap-8">
        <section class="w-2/3 h-full overflow-y-auto card shadow-lg rounded-lg border">
            <div id="table-container">
                </div>
        </section>
        <section class="w-1/3 h-full">
            <div class="flex flex-col justify-between h-full card text-white bg-gray-900 dark:bg-black p-4 rounded-lg shadow-lg">
                <div>
                    <h2 class="font-bold mb-4 text-center">Electronics CLI</h2>
                    <div id="cli" class="h-[calc(80vh-120px)] overflow-y-auto bg-black p-3 font-mono text-sm rounded-lg">
                        <p class="text-green-400">Welcome to Electronics CLI!</p>
                        <p class="text-green-400">Type 'HELP' to see available commands.</p>
                    </div>
                </div>
                <div class="relative">
                    <span class="absolute left-3 top-1/2 -translate-y-1/2 text-green-400 font-mono">></span>
                    <input type="text" id="cli-input" class="w-full p-2 pl-8 bg-gray-800 text-green-300 border border-gray-700 rounded-lg outline-none focus:ring-2 focus:ring-green-500" placeholder="Enter command...">
                </div>
            </div>
        </section>
    </main>

    <script>
        const cli = document.getElementById('cli');
        const cliInput = document.getElementById('cli-input');
        const themeToggle = document.getElementById('theme-toggle');
        const lightIcon = document.getElementById('theme-icon-light');
        const darkIcon = document.getElementById('theme-icon-dark');
        const html = document.documentElement;

        // --- Theme Toggler Logic ---
        function applyTheme(theme) {
            if (theme === 'dark') {
                html.classList.add('dark');
                document.body.classList.remove('theme-light');
                document.body.classList.add('theme-dark');
                lightIcon.classList.add('hidden');
                darkIcon.classList.remove('hidden');
                localStorage.setItem('theme', 'dark');
            } else {
                html.classList.remove('dark');
                document.body.classList.remove('theme-dark');
                document.body.classList.add('theme-light');
                lightIcon.classList.remove('hidden');
                darkIcon.classList.add('hidden');
                localStorage.setItem('theme', 'light');
            }
        }

        themeToggle.addEventListener('click', () => {
            const currentTheme = localStorage.getItem('theme') || 'light';
            applyTheme(currentTheme === 'light' ? 'dark' : 'light');
        });

        // Apply theme on initial load
        applyTheme(localStorage.getItem('theme') || 'light');

        // --- CLI Logic ---
        cliInput.addEventListener('keydown', function(event) {
            if (event.key === 'Enter') {
                const command = cliInput.value.trim();
                if (command) {
                    appendToCLI(`<span class="text-gray-500">> ${command}</span>`);
                    cliInput.value = '';

                    // Kirim ke file ini sendiri dengan method POST
                    fetch('index.php', {
                        method: 'POST',
                        headers: { 'Content-Type': 'application/json' },
                        body: JSON.stringify({ command })
                    })
                    .then(response => response.json())
                    .then(data => {
                        appendToCLI(`<span class="text-yellow-400">${data.message}</span>`);
                        if (data.refresh) {
                            refreshTable(data.search);
                        }
                    });
                }
            }
        });

        function appendToCLI(message) {
            const output = document.createElement('p');
            output.innerHTML = message;
            cli.appendChild(output);
            cli.scrollTop = cli.scrollHeight;
        }

        // --- Table Refresh Logic ---
        function refreshTable(search = null) {
            let url = 'index.php?action=list';
            if (search) {
                url += '&search=' + search;
            }
            fetch(url)
            .then(response => response.text())
            .then(html => document.getElementById('table-container').innerHTML = html);
        }

        // --- Sidebar Logic ---
        function toggleSidebar() {
            const sidebar = document.querySelector('aside');
            sidebar.classList.toggle('translate-x-full');
        }

        // Initial table load
        document.addEventListener('DOMContentLoaded', () => {
            refreshTable();
        });
    </script>
</body>
</html>