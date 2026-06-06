# OOPS Problem of the Week: - 
# TOPIC IS — INTERFACE                                                                                                                                                                                                                   
# A library needs to develop an online application for two types of users/roles, Adults and 
# children. Both of these users should be able to register an account.  
# Any user who is less than 12 years of age will be registered as a child and they can borrow a 
# “Kids” category book for 10 days, whereas an adult can borrow “Fiction” category books which 
# need to be returned within 7 days.  
# Note: In future, more users/roles might be added to the library where similar rules will be 
# enforced.  
# Develop Interfaces and classes for the categories mentioned above.   
# 1. Create an interface LibraryUser with the following methods declared, 
# Method Name 
# registerAccount 
# requestBook 
# 2. Create 2 classes “KidUsers” and “AdultUser” which implements the LibraryUser interface. 
# 3.  Both the classes should have two instance variables as specified below. 
# Instance variables  Data type 
# age int 
# bookType String 
# 4. The methods in the KidUser class should perform the following logic.  
# registerAccount function: 
# if age < 12, a message displaying “You have successfully registered under a Kids Account” should 
# be displayed in the console.  
# If(age>12), a message displaying, “Sorry, Age must be less than 12 to register as a kid” should be 
# displayed in the console.  
# requestBook function:  
# if bookType is “Kids”, a message displaying “Book Issued successfully, please return the book 
# within 10 days” should be displayed in the console.  
# Else, a message displaying, “Oops, you are allowed to take only kids books” should be displayed 
# in the console.  
# 5. The methods in the AdultUser class should perform the following logic.  
# registerAccount  function: 
# if age > 12, a message displaying “You have successfully registered under an Adult Account” 
# should be displayed in the console. 
# If age<12, a message displaying, “Sorry, Age must be greater than 12 to register as an adult” 
# should be displayed in the console. 
# requestBook function: 
# if bookType is “Fiction”, a message displaying “Book Issued successfully, please return the book 
# within 7 days” should be displayed in the console. 
# Else, a message displaying, “Oops, you are allowed to take only adult Fiction books” should be 
# displayed in the console. 

from abc import ABC,abstractmethod

class LibraryUser(ABC):
    
    @abstractmethod
    def registerAccount(self):
        pass
    
    @abstractmethod
    def requestBook(self):
        pass
    

class KidUsers(LibraryUser):
    
    def __init__(self,age,bookType):
        self.age = age
        self.bookType = bookType
        
    def registerAccount(self):
        if self.age < 12:
            print("You have successfully registered under a Kids Account")
        else:
            print("Sorry, Age must be less than 12 to register as a kid")
    
    def requestBook(self):
        if self.bookType == "Kids":
            print("Book Issued successfully, please return the book within 10 days")
        else:
            print("Oops, you are allowed to take only kids books")
            
            
class AdultUser(LibraryUser):
    
    def __init__(self, age,bookType):
        self.age = age
        self.bookType = bookType
        
    def registerAccount(self):
        if self.age > 12:
            print("You have successfully registered under an Adult Account")
        else:
            print("Sorry, Age must be greater than 12 to register as an adult")
            
    def requestBook(self):
        if self.bookType == "Fiction":
            print("Book Issued successfully, please return the book within 7 days")
        else:
            print("Oops, you are allowed to take only adult Fiction books")
                
            
 
print("Instance of KidUser")
print()
    
kid1 = KidUsers(10,"Kids")
kid1.registerAccount()
kid1.requestBook()
    
print()
    
kid2 = KidUsers(20,"Fiction")
kid2.registerAccount()
kid2.requestBook()

print()
    
print("Instance of AdultUser")
print()
    
adult1 = AdultUser(9,"Kids")
adult1.registerAccount()
adult1.requestBook()

print()

adult1 = AdultUser(20,"Fiction")
adult1.registerAccount()
adult1.requestBook()
    
    
    
    
    
    
    
    