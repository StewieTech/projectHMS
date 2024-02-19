# projectHMS

Project for Object-Oriented Software Development Using C++

## Contact
-  <mjlovsin-lablans@myseneca.ca>;
-  <ocostantino1@myseneca.ca>;
-  <swu106@myseneca.ca>
-  <estewart14@myseneca.ca>

 ## Instructions for git
- git clone https://github.com/StewieTech/projectHMS.git
- git pull
- git add .
  - this add's everything. We may want to add individual files to avoid merge conflicts 
- git commit -m "Add feature"
- git push origin master


## File Structure
- `/src` - contains cpp files used for implementation
- `main.cpp`
- `/userInterface`
 - `userInterface.cpp`
   
- `/include` - contains header files used for classes
- `/userInterface`
 - `userInterface.h`
   
- `/docs` - contains documentation
  
- `/tests` - contains test files

## Build Instructions
- g++ userInterface.cpp -o userInterface
  - to compile the single file   
- g++ -o projectHMS src/*.cpp -Iinclude
  - this compiles the entire project 
- ./projectHMS
  - this runs the entire project 
