#include "Electronic.cpp"
// DEKLARASI MAKRO (maap kalo campur indo soalnya bekas dasprog hehe)
#define RESET               "\033[0m"      // Reset warna ke default
#define BLACK               "\033[30m"     // Teks hitam
#define RED                 "\033[31m"     // Teks merah
#define GREEN               "\033[32m"     // Teks hijau
#define YELLOW              "\033[33m"     // Teks kuning
#define BLUE                "\033[34m"     // Teks biru
#define MAGENTA             "\033[35m"     // Teks magenta
#define PINK                "\033[1;35m"   // Teks pink
#define CYAN                "\033[36m"     // Teks cyan
#define WHITE               "\033[37m"     // Teks putih
#define BOLD                "\033[1m"      // Membuat teks tebal
#define BRIGHT_RED          "\033[91m"     // Merah Terang
#define BRIGHT_GREEN        "\033[92m"     // Hijau Terang
#define BRIGHT_YELLOW       "\033[93m"     // Kuning Terang
#define BRIGHT_BLUE         "\033[94m"     // Biru Terang
#define BRIGHT_CYAN         "\033[96m"     // Cyan Terang

// Declare global variable for set the length of the column
int colId = 2, colName = 4, colCategory = 8, colPrice = 5;

// Procedure to show the intro
void intro(){
    cout << "\n=================================================\n";
    cout << "||         Welcome to Electronic Shop!         ||\n";
    cout << "=================================================\n\n";
}

// Procedure to delay
void delay() {
    this_thread::sleep_for(chrono::milliseconds(500));
}

// Procedure to show the outro
void outro() {
    cout << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~" 
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~" 
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~"
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~"
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~"
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~"
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~"
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~"
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~"
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~"
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~"
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~"
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~"
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+" << BRIGHT_BLUE "~"
         << BRIGHT_RED "+" << BRIGHT_BLUE "~" << BRIGHT_RED "+\n";
    delay();

    cout << " " << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-" << GREEN "-" << BRIGHT_YELLOW "-" << GREEN "-"
         << BRIGHT_YELLOW "-\n";
    delay();

    cout << PINK "  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"; delay();
    cout << "   \\\\        " << BRIGHT_YELLOW "SELAMAT TINGGAL DI ELECTRONIC SHOP" << PINK "        //\n"; delay();
    cout << "    \\\\         " << BRIGHT_YELLOW "TUGAS PRAKTIKUM 1 (TP1) DESAIN" << PINK "         //\n"; delay();
    cout << "     \\\\           " << BRIGHT_YELLOW "PEMROGRAMAN BERORIENTASI" << PINK "           //\n"; delay();
    cout << "      \\\\            " << BRIGHT_YELLOW "OBJEK (DPBO), GACOR!!" << PINK "           //\n"; delay();
    cout << "       \\\\                 " << BRIGHT_YELLOW "MANTAP!!" << PINK "                 // \n"; delay();
    // cout << "   \\\\        " << BRIGHT_YELLOW "SELAMAT TINGGAL DI ZICOFARRY DBMS" << PINK "        //\n"; delay();
    // cout << "    \\\\         " << BRIGHT_YELLOW "TUGAS MASA DEPAN DASAR-DASAR" << PINK "          //\n"; delay();
    // cout << "     \\\\           " << BRIGHT_YELLOW "PEMROGRAMAN, DEMI MASA" << PINK "            //\n"; delay();
    // cout << "      \\\\             " << BRIGHT_YELLOW "DEPAN YANG LEBIH" << PINK "              //\n"; delay();
    // cout << "       \\\\                 " << BRIGHT_YELLOW "CERAH!!" << PINK "                 // \n"; delay();
    cout << PINK "        vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n" RESET; delay();

    cout << CYAN "         -----------------------------------------\n"; delay();
    cout << RED "          ~+~+~+~~+~ " << BRIGHT_YELLOW "SEMOGA KITA SEMUA" << RED " +~+~+~+~+~\n"; delay();
    cout << GREEN "           ~+~+~+~+~+~+ " << BRIGHT_YELLOW "MASUK SURGA" << GREEN " +~+~+~+~+~+~\n"; delay();
    cout << BLUE "            ~+~+~+~+~+~+~+ " << BRIGHT_YELLOW "AAMIIN" << BLUE " ~+~+~+~+~+~+~\n"; delay();
    cout << CYAN "              --------------------------------\n"; delay();
    cout << BRIGHT_YELLOW "                vvvvvvvvvvvvvvvvvvvvvvvvvvvv\n"; delay();
    cout << "                  \\\\\\\\\\\\\\\\\\\\\\\\////////////\n"; delay();
    cout << "                             \\/\n"; delay();
    cout << "                               \n" RED; delay();
    cout << "                             ❤\n" RESET;
}

// Procudure to print help
void help() {
    cout << "============================================================================\n";
    cout << "|+------------------------------------------------------------------------+|\n";
    cout << "||                                                                        ||\n";
    cout << "||     <<<<<<<<<<<<<  BUKU PANDUAN MENGGUNAKAN KODE  >>>>>>>>>>>>>        ||\n";
    cout << "||                                                                        ||\n";
    cout << "||     1. Pilih Masukan Perintah Dengan Format Seperti Di Bawah.          ||\n";
    cout << "||        TIDAK CASE SENSITIVE!!!!                                        ||\n";
    cout << "||        a. Perintah Langsung:                                           ||\n";
    cout << "||           HELP                                                         ||\n";
    cout << "||           -Berfungsi Untuk Menampilkan Buku Panduan.                   ||\n";
    cout << "||           SHOW                                                         ||\n";
    cout << "||           -Berfungsi Untuk Menampilkan Data Saat Ini.                  ||\n";
    cout << "||           EXIT                                                         ||\n";
    cout << "||           -Berfungsi Untuk Mengakhiri Program.                         ||\n";
    cout << "||                                                                        ||\n";
    cout << "||        b. Perintah Data:                                               ||\n";
    cout << "||             +----------+                                               ||\n";
    cout << "||             | PERINTAH |                                               ||\n";
    cout << "||             +----------+                                               ||\n";
    cout << "||             |  INSERT  |                                               ||\n";
    cout << "||             |  UPDATE  |                                               ||\n";
    cout << "||             |  DELETE  |                                               ||\n";
    cout << "||             |  SEARCH  |                                               ||\n";
    cout << "||             +----------+                                               ||\n";
    cout << "||                                                                        ||\n";
    cout << "||     2. Jika Anda Memilih INSERT. Maka Tulis Nama, Kategori, dan        ||\n";
    cout << "||        Harga (String Wajib Diapit Dengan Tanda Petik Dua,              ||\n";
    cout << "||        CTH: \"Handphone\")                                               ||\n";
    cout << "||        FORMAT QUERY :                                                  ||\n";
    cout << "||          INSERT \"[Nama]\" \"[Kategori]\" [Harga]                          ||\n";
    cout << "||                                                                        ||\n";
    cout << "||     3. Jika Anda Memilih UPDATE. Maka Tulis ID, Nama, Kategori         ||\n";
    cout << "||        dan Harga (String Wajib Diapit Dengan Tanda Petik Dua,          ||\n";
    cout << "||        CTH: \"Handphone\")                                               ||\n";
    cout << "||        FORMAT QUERY :                                                  ||\n";
    cout << "||          UPDATE [ID] \"[Nama]\" \"[Kategori]\" [Harga]                     ||\n";
    cout << "||                                                                        ||\n";
    cout << "||     4. Jika Anda Memilih DELETE, Cukup Tulis ID Nya Saja.              ||\n";
    cout << "||        FORMAT QUERY :                                                  ||\n";
    cout << "||          DELETE [ID]                                                   ||\n";
    cout << "||                                                                        ||\n";
    cout << "||     5. Jika Anda Memilih SEARCH. Maka Cukup Tuliskan Nama.             ||\n";
    cout << "||        (String Wajib Diapit Dengan Tanda Petik Dua, CTH: \"Handphone\")  ||\n";
    cout << "||        FORMAT QUERY :                                                  ||\n";
    cout << "||          SEARCH \"[Nama]\"                                               ||\n";
    cout << "||                                                                        ||\n";
    cout << "||                                                                        ||\n";
    cout << "|+------------------------------------------------------------------------+|\n";
    cout << "============================================================================\n";
}

// Procedure to print the header
void head(int col1, int col2, int col3, int col4){
    cout << "+-"; for(int i = 0; i < col1; i++) cout << "-";
    cout << "-+-"; for(int i = 0; i < col2; i++) cout << "-";
    cout << "-+-"; for(int i = 0; i < col3; i++) cout << "-";
    cout << "-+-"; for(int i = 0; i < col4; i++) cout << "-";
    cout << "-+" << endl;

    cout << "| "; for(int i = 0; i < col1 - 2; i+=2) cout << " ";
    cout << "ID"; for(int i = 0; i < col1 - 2; i+=2) cout << " ";
    cout << " | "; for(int i = 0; i < col2 - 4; i+=2) cout << " ";
    cout << "NAME"; for(int i = 0; i < col2 - 4; i+=2) cout << " ";
    cout << " | "; for(int i = 0; i < col3 - 8; i+=2) cout << " ";
    cout << "CATEGORY"; for(int i = 0; i < col3 - 8; i+=2) cout << " ";
    cout << " | "; for(int i = 0; i < col4 - 5; i+=2) cout << " ";
    cout << "PRICE"; for(int i = 0; i < col4 - 5; i+=2) cout << " ";
    cout << " |" << endl;


    cout << "+-"; for(int i = 0; i < col1; i++) cout << "-";
    cout << "-+-"; for(int i = 0; i < col2; i++) cout << "-";
    cout << "-+-"; for(int i = 0; i < col3; i++) cout << "-";
    cout << "-+-"; for(int i = 0; i < col4; i++) cout << "-";
    cout << "-+" << endl;
}

// Procedure to print rows
void row(int id, string name, string category, int price, int col1, int col2, int col3, int col4){
    cout << "| "; for(int i = 0; i < col1 - to_string(id).length(); i++) cout << " ";
    cout << id <<  " | " << name; for(int i = 0; i < col2 - name.length(); i++) cout << " ";
    cout << " | " << category; for(int i = 0; i < col3 - category.length(); i++) cout << " ";
    cout << " | "; for(int i = 0; i < col4 - to_string(price).length(); i++) cout << " ";
    cout << price << " |" << endl;
}

// Procedure to print footer
void foot(int col1, int col2, int col3, int col4){
    cout << "+-"; for(int i = 0; i < col1; i++) cout << "-";
    cout << "-+-"; for(int i = 0; i < col2; i++) cout << "-";
    cout << "-+-"; for(int i = 0; i < col3; i++) cout << "-";
    cout << "-+-"; for(int i = 0; i < col4; i++) cout << "-";
    cout << "-+" << endl;
}

// Procedure to count the length of the column
void cLeng(vector<Electronic> v){
    // reset the length of the column
    colId = 2, colName = 4, colCategory = 8, colPrice = 5;

    // loop for each row
    for(Electronic i: v){
        // find the longest, if its odd then plus 1
        colId = max(colId, static_cast<int>(to_string(i.getId()).length())); if(colId % 2 == 1) colId++;
        colName = max(colName, static_cast<int>(i.getName().length())); if(colName % 2 == 1) colName++;
        colCategory = max(colCategory, static_cast<int>(i.getCategory().length())); if(colCategory % 2 == 1) colCategory++;
        colPrice = max(colPrice, static_cast<int>(to_string(i.getPrice()).length())); if(colPrice % 2 == 0) colPrice++;
    }
}

int main(){
    int idx = 1;
    vector<Electronic> v;
    string input;
    help(); intro();
    do{
        cout << "Electro Shop >> "; cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::toupper);

        // Condition if its not "EXIT"
        if(input != "EXIT"){
            Electronic now;
            int price;
            string name, category;

            if(input == "INSERT"){
                cin.ignore(); getline(cin, name, '"'); getline(cin, name, '"');
                cin.ignore(); getline(cin, category, '"'); getline(cin, category, '"');
                cin >> price;
                now = Electronic(idx, name, category, price);
                v.push_back(now); idx++;
                cout << "SUCCESS: A new data has been added, lalala yeyeyeye~\n\n";
            }else if(input == "UPDATE"){
                int id; cin >> id;
                cin.ignore(); getline(cin, name, '"'); getline(cin, name, '"');
                cin.ignore(); getline(cin, category, '"'); getline(cin, category, '"');
                cin >> price;

                // Updating the data
                v[id - 1].setName(name);
                v[id - 1].setCategory(category);
                v[id - 1].setPrice(price);
                cout << "SUCCESS: Data with id " << id << " has been updated, lalala yeyeyeye~\n\n";
            }else if(input == "DELETE"){
                int id; cin >> id;
                v.erase(v.begin() + id - 1);
                cout << "SUCCESS: Data with id " << id << " has been deleted, lalala yeyeyeye~\n\n";
            }else if(input == "SEARCH"){
                cin.ignore(); getline(cin, name, '"'); getline(cin, name, '"');
                if(v.size() == 0) cout << "Data is empty!\n\n";
                else{
                    int i = 0;
                    bool found = false;
                    while(i < v.size() && !found){
                        if(v[i].getName() == name){
                            found = true;
                            int nowId = max(2, static_cast<int>(to_string(v[i].getId()).length())); if(nowId % 2 == 1) nowId++;
                            int nowName = max(4, static_cast<int>(v[i].getName().length())); if(nowName % 2 == 1) nowName++;
                            int nowCategory = max(8, static_cast<int>(v[i].getCategory().length())); if(nowCategory % 2 == 1) nowCategory++;
                            int nowPrice = max(5, static_cast<int>(to_string(v[i].getPrice()).length())); if(nowPrice % 2 == 0) nowPrice++;
                            head(nowId, nowName, nowCategory, nowPrice);
                            row(v[i].getId(), v[i].getName(), v[i].getCategory(), v[i].getPrice(), nowId, nowName, nowCategory, nowPrice);
                            foot(nowId, nowName, nowCategory, nowPrice);
                        }else{
                            i++;
                        }
                    }

                    if(!found) cout << "ERROR: Data with name '" << name << "' not found!\n\n";
                }
            }else if(input == "SHOW"){
                cLeng(v);
                if(v.size() == 0) cout << "Data is empty!\n\n";
                else{
                    head(colId, colName, colCategory, colPrice);
                    for(Electronic i : v) row(i.getId(), i.getName(), i.getCategory(), i.getPrice(), colId, colName, colCategory, colPrice);
                    foot(colId, colName, colCategory, colPrice);
                    cout << "Displaying " << v.size() << " record(s).\n\n";
                }
            }else if(input == "HELP"){
                help();
            }else cout << "ERROR: Command not found!\n\n";
        }
    }while(input != "EXIT");
    outro();
    return 0;
}