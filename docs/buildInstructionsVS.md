# Setting Up Your Project in Visual Studio

## 1. Create a New Project:
- Open Visual Studio.
- Go to `File` > `New` > `Project...`.
- Choose a C++ project template. For a simple compilation, a "Console App" under "C++" will suffice.
- Name your project, choose a location, and click `Create`.

## 2. Add Your Existing Files:
- Right-click on your project in the Solution Explorer (usually on the right side).
- Choose `Add` > `Existing Item...`.
- Navigate to where your `.cpp` and `.h` files are located (`UIrebuild.cpp`, `medicalStaffVF.cpp`, `procedureVF.cpp`, etc.), select them, and click `Add`.

## 3. Build and Run Your Project:
- To compile and run, click on `Build` > `Build Solution` for compiling.
- Then, go to `Debug` > `Start Without Debugging` to run your application.

Visual Studio compiles all `.cpp` files included in the project into a single executable by default, but you can control what is included in the build through the use of project configurations and file properties. Here's how you can manage which files are compiled without deleting them:

## Excluding Files from the Build

### 1. Exclude Files from Build:
- In the Solution Explorer pane within Visual Studio, find the `.cpp` files you do not wish to include in the current build.
- Right-click on each file you want to exclude, select `Properties`.
- In the `Properties` window, under `Configuration Properties` > `General`, find the `Excluded From Build` property.
- Set `Excluded From Build` to `Yes` for each file you do not want to compile.
- Click `OK` to apply the changes.

## Creating Custom Build Configurations

If you frequently switch between different sets of files for compilation, consider creating custom build configurations:

### 1. Open Configuration Manager:
- Go to `Build` > `Configuration Manager...`.

### 2. Create a New Configuration:
- Click on the `<Active solution configuration>` dropdown and select `<New...>`.
- Name your new configuration (e.g., "UIRebuildBuild") and choose to copy settings from an existing configuration if applicable.
- Click `OK`.

### 3. Adjust Configuration for Specific Files:
- With your new configuration selected in the Configuration Manager, go back to the Solution Explorer and set the `Excluded From Build` property for each file as needed, just as described above. This way, these settings apply only when your custom configuration is active.

### 4. Switch Configurations as Needed:
- Use the Configuration Manager or the solution configurations dropdown (next to the green play button on the toolbar) to switch between configurations. Each configuration can have a different set of files included in the build.

# Running the Executable

## From Visual Studio:
1. After the build process, you can simply click the green arrow button (Start Debugging) in the toolbar, or press `F5`. This will run the built executable within Visual Studio.
2. If you want to run it without the debugger attached, you can use `Ctrl+F5` or go to `Debug` > `Start Without Debugging`.

# Related Documentation Links

1. **Creating a New Project**:
   - [Create a C++ console app project](https://docs.microsoft.com/en-us/cpp/get-started/tutorial-console-cpp)

2. **Building and Running a Project**:
   - [Build and clean projects and solutions in Visual Studio](https://docs.microsoft.com/en-us/visualstudio/ide/building-and-cleaning-projects-and-solutions-in-visual-studio)
   - [Start debugging in Visual Studio](https://docs.microsoft.com/en-us/visualstudio/debugger/debugger-feature-tour)

3. **Creating and Managing Configurations**:
   - [Understanding Build Configurations](https://docs.microsoft.com/en-us/visualstudio/ide/understanding-build-configurations)
   - [How to: Create and edit configurations](https://docs.microsoft.com/en-us/visualstudio/ide/how-to-create-and-edit-configurations)
