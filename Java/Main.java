import java.util.ArrayList;
import java.util.Scanner;

public class Main{

    // Declare global variable for set the length of the column
    static int colId = 2, colName = 4, colCategory = 8, colPrice = 5;

    // Procedure to show the intro
    public static void intro(){
        System.out.println("\n=================================================");
        System.out.println("||         Welcome to Electronic Shop!         ||");
        System.out.println("=================================================\n");
    }

    // Procedure to print the header
    public static void head(int col1, int col2, int col3, int col4){
        System.out.print("+-"); for(int i = 0; i < col1; i++) System.out.print("-");
        System.out.print("-+-"); for(int i = 0; i < col2; i++) System.out.print("-");
        System.out.print("-+-"); for(int i = 0; i < col3; i++) System.out.print("-");
        System.out.print("-+-"); for(int i = 0; i < col4; i++) System.out.print("-");
        System.out.print("-+\n");

        System.out.print("| "); for(int i = 0; i < col1 - 2; i+=2) System.out.print(" ");
        System.out.print("ID"); for(int i = 0; i < col1 - 2; i+=2) System.out.print(" ");
        System.out.print(" | "); for(int i = 0; i < col2 - 4; i+=2) System.out.print(" ");
        System.out.print("NAME"); for(int i = 0; i < col2 - 4; i+=2) System.out.print(" ");
        System.out.print(" | "); for(int i = 0; i < col3 - 8; i+=2) System.out.print(" ");
        System.out.print("CATEGORY"); for(int i = 0; i < col3 - 8; i+=2) System.out.print(" ");
        System.out.print(" | "); for(int i = 0; i < col4 - 5; i+=2) System.out.print(" ");
        System.out.print("PRICE"); for(int i = 0; i < col4 - 5; i+=2) System.out.print(" ");
        System.out.print(" |\n");


        System.out.print("+-"); for(int i = 0; i < col1; i++) System.out.print("-");
        System.out.print("-+-"); for(int i = 0; i < col2; i++) System.out.print("-");
        System.out.print("-+-"); for(int i = 0; i < col3; i++) System.out.print("-");
        System.out.print("-+-"); for(int i = 0; i < col4; i++) System.out.print("-");
        System.out.print("-+\n");
    }

    // Procedure to print rows
    public static void row(int id, String name, String category, int price, int col1, int col2, int col3, int col4){
        System.out.print("| "); for(int i = 0; i < col1 - String.valueOf(id).length(); i++) System.out.print(" ");
        System.out.print(id + " | " + name); for(int i = 0; i < col2 - name.length(); i++) System.out.print(" ");
        System.out.print(" | " + category); for(int i = 0; i < col3 - category.length(); i++) System.out.print(" ");
        System.out.print(" | "); for(int i = 0; i < col4 - String.valueOf(price).length(); i++) System.out.print(" ");
        System.out.print(price + " |\n");
    }

    // Procedure to print footer
    public static void foot(int col1, int col2, int col3, int col4){
        System.out.print("+-"); for(int i = 0; i < col1; i++) System.out.print("-");
        System.out.print("-+-"); for(int i = 0; i < col2; i++) System.out.print("-");
        System.out.print("-+-"); for(int i = 0; i < col3; i++) System.out.print("-");
        System.out.print("-+-"); for(int i = 0; i < col4; i++) System.out.print("-");
        System.out.print("-+\n");
    }

    // Procedure to count the length of the column
    public static void cLeng(ArrayList<Electronic> v){
        // reset the length of the column
        colId = 2; colName = 4; colCategory = 8; colPrice = 5;

        // loop for each row
        for(Electronic i: v){
            // find the longest, if its odd then plus 1
            colId = Math.max(colId, String.valueOf(i.getId()).length()); if(colId % 2 == 1) colId++;
            colName = Math.max(colName, i.getName().length()); if(colName % 2 == 1) colName++;
            colCategory = Math.max(colCategory, i.getCategory().length()); if(colCategory % 2 == 1) colCategory++;
            colPrice = Math.max(colPrice, String.valueOf(i.getPrice()).length()); if(colPrice % 2 == 0) colPrice++;
        }
    }

    public static void main(String[] args){
        int idx = 1;
        ArrayList<Electronic> v = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        
        intro();
        boolean stop = false;
        do{
            System.out.print("Electro Shop >> ");
            String input = sc.nextLine().trim();
            String[] userInput = input.split(" ", 2);
            String inputCmd = userInput[0].toUpperCase();
            String str = userInput.length > 1 ? userInput[1] : "";

            // Condition if its not "EXIT"
            if(!inputCmd.equals("EXIT")){
                Electronic now;
                
                if(inputCmd.equals("ADD")){
                    String[] parts = str.split("\"");
                    String name = parts[1].trim();
                    String category = parts[3].trim();
                    int price = Integer.parseInt(parts[4].trim());

                    now = new Electronic(idx, name, category, price);
                    v.add(now); idx++;
                    System.out.print("SUCCESS: A new data has been addess, lalala yeyeyeye~\n\n");
                }else if(inputCmd.equals("UPDATE")){
                    String[] parts = str.split("\"");
                    int id = Integer.parseInt(parts[0].trim());
                    String name = parts[1].trim();
                    String category = parts[3].trim();
                    int price = Integer.parseInt(parts[4].trim());
                    
                    // Updating the data
                    Electronic el = v.get(id - 1);
                    el.setName(name);
                    el.setCategory(category);
                    el.setPrice(price);
                    System.out.print("SUCCESS: Data with id " + id + " has been updated, lalala yeyeyeye~\n\n");
                }else if(inputCmd.equals("DELETE")){
                    int id = Integer.parseInt(str.trim());
                    v.remove(id - 1);
                    System.out.print("SUCCESS: Data with id " + id + " has been deleted, lalala yeyeyeye~\n\n");
                }else if(inputCmd.equals("SEARCH")){
                    String[] parts = str.split("\"");
                    String name = parts[1].trim();
                    if(v.isEmpty()) System.out.print("ERROR: Data is empty!\n\n");
                    else{
                        int i = 0;
                        boolean found = false;
                        while(i < v.size() && !found){
                            if(v.get(i).getName().equals(name)){
                                found = true;
                                int nowId = Math.max(2, String.valueOf(v.get(i).getId()).length()); if(nowId % 2 == 1) nowId++;
                                int nowName = Math.max(4, v.get(i).getName().length()); if(nowName % 2 == 1) nowName++;
                                int nowCategory = Math.max(8, v.get(i).getCategory().length()); if(nowCategory % 2 == 1) nowCategory++;
                                int nowPrice = Math.max(5, String.valueOf(v.get(i).getPrice()).length()); if(nowPrice % 2 == 1) nowPrice++;
                                head(nowId, nowName, nowCategory, nowPrice);
                                row(v.get(i).getId(), v.get(i).getName(), v.get(i).getCategory(), v.get(i).getPrice(), nowId, nowName, nowCategory, nowPrice);
                                foot(nowId, nowName, nowCategory, nowPrice);
                            }else{
                                i++;
                            }
                        }

                        if(!found) System.out.print("ERROR: Data with name '" + name + "' not found!\n\n");
                    }
                }else if(inputCmd.equals("SHOW")){
                    cLeng(v);
                    if(v.isEmpty()) System.out.print("ERROR: Data is empty!\n\n");
                    else{
                        head(colId, colName, colCategory, colPrice);
                        for(Electronic i : v) row(i.getId(), i.getName(), i.getCategory(), i.getPrice(), colId, colName, colCategory, colPrice);
                        foot(colId, colName, colCategory, colPrice);
                        System.out.println("Displaying " + v.size() + " record(s).\n");
                    }
                }else if(inputCmd.equals("HELP")){
                    System.out.print("Command Help:\n");

                }else System.out.print("ERROR: Command not found!\n\n");
            }else{
                stop = true;
            }
        }while(!stop);

        sc.close();
    }
}