#include "Electronic.cpp"

// Declare global variable for set the length of the column
int colId = 2, colName = 4, colCategory = 8, colPrice = 5;

// Procedure to show the intro
void intro(){
    cout << "\n=================================================\n";
    cout << "||         Welcome to Electronic Shop!         ||\n";
    cout << "=================================================\n\n";
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
        colPrice = max(colPrice, static_cast<int>(to_string(i.getPrice()).length())); if(colPrice % 2 == 1) colPrice++;
    }
}

int main(){
    int idx = 1;
    vector<Electronic> v;
    string input;
    
    intro();
    do{
        cout << "Electro Shop >>"; cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::toupper);

        // Condition if its not "EXIT"
        if(input != "EXIT"){
            Electronic now;
            int price;
            string name, category;

            if(input == "ADD"){
                cin.ignore(); getline(cin, name, '"'); getline(cin, name, '"');
                cin.ignore(); getline(cin, category, '"'); getline(cin, category, '"');
                cin >> price;
                now = Electronic(idx, name, category, price);
                v.push_back(now); idx++;
                cout << "SUCCESS: A new data has been addess, lalala yeyeyeye~\n\n";
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
                if(v.size() == 0) cout << "ERROR: Data is empty!\n\n";
                else{
                    int i = 0;
                    bool found = false;
                    while(i < v.size() && !found){
                        if(v[i].getName() == name){
                            found = true;
                            int nowId = max(nowId, static_cast<int>(to_string(v[i].getId()).length())); if(nowId % 2 == 1) nowId++;
                            int nowName = max(nowName, static_cast<int>(v[i].getName().length())); if(nowName % 2 == 1) nowName++;
                            int nowCategory = max(nowCategory, static_cast<int>(v[i].getCategory().length())); if(nowCategory % 2 == 1) nowCategory++;
                            int nowPrice = max(nowPrice, static_cast<int>(to_string(v[i].getPrice()).length())); if(nowPrice % 2 == 1) nowPrice++;
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
                if(v.size() == 0) cout << "ERROR: Data is empty!\n\n";
                else{
                    head(colId, colName, colCategory, colPrice);
                    for(Electronic i : v) row(i.getId(), i.getName(), i.getCategory(), i.getPrice(), colId, colName, colCategory, colPrice);
                    foot(colId, colName, colCategory, colPrice);
                }
            }else if(input == "HELP"){
                cout << "Command Help:\n";

            }else cout << "ERROR: Command not found!\n\n";
        }
    }while(input != "EXIT");

    return 0;
}