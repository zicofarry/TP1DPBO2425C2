# Class Electronic
class Electronic:
    # Attribute
    __id = 0
    __name = ""
    __category = ""
    __price = 0

    # Constructor
    def __init__(self, id = 0, name = "", category = "", price = 0):
        self.__id = id
        self.__name = name
        self.__category = category
        self.__price = price
    
    # Setter and getter
    def setId(self, id):
        self.__id = id

    def getId(self):
        return self.__id
    
    def setName(self, name):
        self.__name = name

    def getName(self):
        return self.__name
    
    def setCategory(self, category):
        self.__category = category

    def getCategory(self):
        return self.__category
    
    def setPrice(self, price):
        self.__price = price

    def getPrice(self):
        return self.__price