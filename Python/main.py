from Electronic import *
from tabulate import tabulate
import time

# ANSI warna
RESET = "\033[0m"
BRIGHT_RED = "\033[91m"
BRIGHT_BLUE = "\033[94m"
BRIGHT_YELLOW = "\033[93m"
GREEN = "\033[92m"
PINK = "\033[95m"
CYAN = "\033[96m"
RED = "\033[31m"
BLUE = "\033[34m"


# Procedure to print the intro
def intro():
    print("\n=================================================")
    print("||         Welcome to Electronic Shop!         ||")
    print("=================================================\n")

def delay():
    time.sleep(0.1)

def outro():
    print((BRIGHT_RED + "+" + BRIGHT_BLUE + "~") * 29 + BRIGHT_RED + "+")
    delay()

    print(" " + (BRIGHT_YELLOW + "-" + GREEN + "-") * 28 + BRIGHT_YELLOW + "-")
    delay()

    print(PINK + "  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^")
    delay()
    print("   \\\\        " + BRIGHT_YELLOW + "SELAMAT TINGGAL DI ELECTRONIC SHOP" + PINK + "       //")
    delay()
    print("    \\\\         " + BRIGHT_YELLOW + "TUGAS PRAKTIKUM 1 (TP1) DESAIN" + PINK + "        //")
    delay()
    print("     \\\\           " + BRIGHT_YELLOW + "PEMROGRAMAN BERORIENTASI" + PINK + "          //")
    delay()
    print("      \\\\            " + BRIGHT_YELLOW + "OBJEK (DPBO), GACOR!!" + PINK + "          //")
    delay()
    print("       \\\\                 " + BRIGHT_YELLOW + "MANTAP!!" + PINK + "                // ")
    delay()
    print(PINK + "        vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" + RESET)
    delay()

    print(CYAN + "         -----------------------------------------")
    delay()
    print(RED + "          ~+~+~+~~+~ " + BRIGHT_YELLOW + "SEMOGA KITA SEMUA" + RED + " +~+~+~+~+~")
    delay()
    print(GREEN + "           ~+~+~+~+~+~+ " + BRIGHT_YELLOW + "MASUK SURGA" + GREEN + " +~+~+~+~+~+~")
    delay()
    print(BLUE + "            ~+~+~+~+~+~+~+ " + BRIGHT_YELLOW + "AAMIIN" + BLUE + " ~+~+~+~+~+~+~")
    delay()
    print(CYAN + "              --------------------------------")
    delay()
    print(BRIGHT_YELLOW + "                vvvvvvvvvvvvvvvvvvvvvvvvvvvv")
    delay()
    print("                  \\\\\\\\\\\\\\\\\\\\\\\\////////////")
    delay()
    print("                             \\/")
    delay()
    print("                               " + RED)
    delay()
    print("                             ❤" + RESET)

def help():
    print("============================================================================")
    print("|+------------------------------------------------------------------------+|")
    print("||                                                                        ||")
    print("||     <<<<<<<<<<<<<  BUKU PANDUAN MENGGUNAKAN KODE  >>>>>>>>>>>>>        ||")
    print("||                                                                        ||")
    print("||     1. Pilih Masukan Perintah Dengan Format Seperti Di Bawah.          ||")
    print("||        TIDAK CASE SENSITIVE!!!!                                        ||")
    print("||        a. Perintah Langsung:                                           ||")
    print("||           HELP                                                         ||")
    print("||           -Berfungsi Untuk Menampilkan Buku Panduan.                   ||")
    print("||           SHOW                                                         ||")
    print("||           -Berfungsi Untuk Menampilkan Data Saat Ini.                  ||")
    print("||           EXIT                                                         ||")
    print("||           -Berfungsi Untuk Mengakhiri Program.                         ||")
    print("||                                                                        ||")
    print("||        b. Perintah Data:                                               ||")
    print("||             +----------+                                               ||")
    print("||             | PERINTAH |                                               ||")
    print("||             +----------+                                               ||")
    print("||             |  INSERT  |                                               ||")
    print("||             |  UPDATE  |                                               ||")
    print("||             |  DELETE  |                                               ||")
    print("||             |  SEARCH  |                                               ||")
    print("||             +----------+                                               ||")
    print("||                                                                        ||")
    print("||     2. Jika Anda Memilih INSERT. Maka Tulis Nama, Kategori, dan        ||")
    print("||        Harga (String Wajib Diapit Dengan Tanda Petik Dua,              ||")
    print("||        CTH: \"Handphone\")                                               ||")
    print("||        FORMAT QUERY :                                                  ||")
    print("||          INSERT \"[Nama]\" \"[Kategori]\" [Harga]                          ||")
    print("||                                                                        ||")
    print("||     3. Jika Anda Memilih UPDATE. Maka Tulis ID, Nama, Kategori         ||")
    print("||        dan Harga (String Wajib Diapit Dengan Tanda Petik Dua,          ||")
    print("||        CTH: \"Handphone\")                                               ||")
    print("||        FORMAT QUERY :                                                  ||")
    print("||          UPDATE [ID] \"[Nama]\" \"[Kategori]\" [Harga]                     ||")
    print("||                                                                        ||")
    print("||     4. Jika Anda Memilih DELETE, Cukup Tulis ID Nya Saja.              ||")
    print("||        FORMAT QUERY :                                                  ||")
    print("||          DELETE [ID]                                                   ||")
    print("||                                                                        ||")
    print("||     5. Jika Anda Memilih SEARCH. Maka Cukup Tuliskan Nama.             ||")
    print("||        (String Wajib Diapit Dengan Tanda Petik Dua, CTH: \"Handphone\")  ||")
    print("||        FORMAT QUERY :                                                  ||")
    print("||          SEARCH \"[Nama]\"                                               ||")
    print("||                                                                        ||")
    print("||                                                                        ||")
    print("|+------------------------------------------------------------------------+|")
    print("============================================================================")
    print("")

# Main function of the program
def main():
    idx = 1
    v = []
    help()
    intro()

    stop = False
    while not stop:
        user = input("Electro Shop >> ").strip().split(maxsplit=1)
        in_cmd = user[0].upper()
        str = user[1] if len(user) > 1 else ""

        if in_cmd == "EXIT":
            stop = True
            outro()
        
        elif in_cmd == "INSERT":
            parts = str.split('"')
            name = parts[1].strip()
            category = parts[3].strip()
            price = int(parts[4].strip())
        
            elc = Electronic(idx, name, category, price)
            v.append(elc)
            idx += 1
            print("SUCCESS: A new data has been added, lalala yeyeyeye~\n")

        elif in_cmd == "DELETE":
            id = int(str.strip())
            v.pop(id-1)
            print(f"SUCCESS: Data with id {id} has been deleted.\n")

        elif in_cmd == "UPDATE":
            parts = str.split('"')
            id = int(parts[0].strip())
            name = parts[1].strip()
            category = parts[3].strip()
            price = int(parts[4].strip())

            v[id-1].setName(name)
            v[id-1].setCategory(category)
            v[id-1].setPrice(price)
            print(f"SUCCESS: Data with id {id} has been updated, lalala yeyeyeye~\n")
        
        elif in_cmd == "SEARCH":
            parts = str.split('"')
            nama = parts[1].strip

            if not v:
                print("Data is empty!\n")
            else:
                found = False
                i = 0
                while i < len(v) and not found:
                    row = v[i]
                    if row.getName() == name:
                        found = True
                        data = [[row.getId(), row.getName(), row.getCategory(), row.getPrice()]]
                        print(tabulate(data, headers=["ID", "NAME", "CATEGORY", "PRICE"], tablefmt="grid"))
                        print("")
                    else:
                        i+=1
                
                if not found:
                    print(f"ERROR: Data with name '{name}' not found!\n")

        elif in_cmd == "SHOW":
            if not v:
                print("Data is empty!\n")
            else:
                data = []
                for row in v:
                    data.append([row.getId(), row.getName(), row.getCategory(), row.getPrice()])
                print(tabulate(data, headers=["ID", "NAME", "CATEGORY", "PRICE"], tablefmt="grid"))
                print(f"Displaying {len(v)} record(s).\n")

        elif in_cmd == "HELP":
            help()

        else:
            print("ERROR: Command not found!\n")

if __name__ == "__main__":
    main()    