// Class Electronic Shop
public class Electronic{
    // Atribute
    private int id;
    private String name;
    private String category;
    private int price;
    
    // Constructor (initializer)
    public Electronic(){
        this.id = 0;
        this.name = "";
        this.category = "";
        this.price = 0;
    }

    // Contructor with parameter
    public Electronic(int id, String name, String category, int price){
        this.id = id;
        this.name = name;
        this.category = category;
        this.price = price;
    }

    // Setter and Getter for id
    public void setId(int id){this.id = id;}
    public int getId(){return this.id;}

    // Setter and Getter for name
    public void setName(String name){this.name = name;}
    public String getName(){return this.name;}

    // Setter and Getter for category
    public void setCategory(String category){this.category = category;}
    public String getCategory(){return this.category;}

    // Setter and Getter for price
    public void setPrice(int price){this.price = price;}
    public int getPrice(){return this.price;}
}