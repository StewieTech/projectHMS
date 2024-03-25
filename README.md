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
  
- `/FINAL` - contains header files used for classes and source files
- `- patient.h
  - patient.cpp
  - appointment.h
  - appointment.cpp
  - medicalStaff.h
  - medidalStaff.cpp
  - procedure.h
  - procedure.cpp
  - exceptions.h
  - exceptions.cpp
  - main.cpp
   
- `/docs` - contains documentation
  
- `/tests` - contains test files
- /include - contains initial files
- /VF - contains scrap versions of files

## Build Instructions
- g++ main.cpp -o userInterface
  - to compile the single file   
- g++ -o projectHMS FINAL/*.cpp -Iinclude
  - this compiles the entire project 
- ./projectHMS
  - this runs the entire project

## Troubleshooting
to include header files in .cpp files use <br>
- #include "../FINAL/userInterface.h"
- ctrl + shift + p in visual studio code then search for c_cpp_properties.json and add to the include path: <br>
 "includePath": [
"${workspaceFolder}/**",
"${workspaceFolder}/projectHMS/FINAL",
],



