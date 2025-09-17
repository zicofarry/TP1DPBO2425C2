from Electronic import *
from tabulate import tabulate

# Procedure to print the intro
def intro():
    print("\n=================================================")
    print("||         Welcome to Electronic Shop!         ||")
    print("=================================================\n")

# Main function of the program
def main():
    idx = 1
    v = []
    intro()

    stop = False
    while not stop:
        user = input("Electro Shop >> ").strip().split(maxsplit=1)
        in_cmd = user[0].upper()
        str = user[1] if len(user) > 1 else ""

        if in_cmd == "EXIT":
            stop = True
        
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
                print("ERROR: Data is empty!\n")
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
                print("ERROR: Data is empty!\n")
            else:
                data = []
                for row in v:
                    data = [[row.getId(), row.getName(), row.getCategory(), row.getPrice()]]
                    print(tabulate(data, headers=["ID", "NAME", "CATEGORY", "PRICE"], tablefmt="grid"))
                    print(f"Displaying {len(v)} record(s).\n")

        elif in_cmd == "HELP":
            print("Command Help:")

        else:
            print("ERROR: Command not found!\n")

if __name__ == "__main__":
    main()    