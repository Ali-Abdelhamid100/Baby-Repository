BABY PHOTOSHOP

CS213 – Object Oriented Programming (OOP)

Faculty of Computers and Artificial Intelligence, Cairo University

Academic Year 2026–2027

---

1. Project Overview

Baby Photoshop is a C++ image-processing application developed as part of the CS213 Object Oriented Programming course at the Faculty of Computers and Artificial Intelligence, Cairo University, under the supervision of Dr. Mohammad El-Ramly.

The application allows users to load images, apply different image-processing filters, preview the results, and save the modified images.

The project was developed using C++ and Qt Widgets, providing a graphical user interface (GUI) for a more interactive image-editing experience.

2. Team Members

- Ali Abdelhamid Ali Abdelhamid         ID: 20251258
- Habiba Nader Hussein Ali              ID: 20250193
- Sama Mounir Mohamed Mohamed           ID: 20250297
- Seif El Deen Ismail Mostafa           ID: 20251201

3. Technologies and Tools

The project uses the following technologies and tools:

- Programming Language: C++
- GUI Framework: Qt 6 Widgets
- Build System: CMake
- IDE: Visual Studio Code
- Compiler: A compatible C++ compiler supported by the installed Qt and CMake environment
- Image Processing Library: Image_Class.h
- Image Loading and Saving Support: stb_image.h and stb_image_write.h
- Version Control: Git and GitHub

Required Software

To build and run the project, install:

1. Qt 6 with the Qt Widgets component.
2. CMake 3.19 or a compatible newer version.
3. A compatible C++ compiler.
4. Visual Studio Code or another supported development environment.
5. Git, if you need to clone the project repository.

The project configuration specifies Qt 6.5 or newer through CMake. A compatible Qt installation and compiler must be available on your system.

4. Main Features

Image Operations

- Open and load images.
- Save modified images.
- Save images using a new file name.
- Support common image formats, including PNG, JPG, JPEG, and BMP.
- Display the loaded image in the graphical interface.

Image Processing Filters

The application includes the following filters:

1. Grayscale
2. Black and White
3. Invert Colors
4. Add Frame
5. Flip Image
6. Rotate Image
7. Darken and Lighten
8. Resize Image
9. Merge Images
10. Detect Edges
11. Crop Image
12. Blur Image
13. Sunlight Effect
14. Old TV Effect
15. Purple Effect
16. Infrared Effect
17. Image Skewing
18. Oil Painting Effect

The available settings depend on the selected filter and its implementation.

Image Editing Controls

The graphical interface also provides image-editing controls, including:

- Undo
- Redo
- Reset Image
- Filter settings
- Image preview and display
- Before-and-after preview, where enabled

5. Project Structure

The project is organized into C++ source files, header files, and the CMake project configuration.

Typical files include:

- "main.cpp" — Application entry point.
- "mainwindow.h" — Main window declarations.
- "mainwindow.cpp" — Main window implementation and GUI functionality.
- "mainwindow.ui" — Qt Designer interface file, if used by the project.
- "Image_Class.h" — Image representation and image-processing support.
- "stb_image.h" — Image loading support.
- "stb_image_write.h" — Image saving support.
- Filter-specific ".h" and ".cpp" files — Implementations of individual image filters.
- "CMakeLists.txt" — Build configuration.

The exact file list should match the files included in the submitted project.

6. How to Set Up the Project

Step 1: Install the Required Tools

Install Qt 6, CMake, and a compatible C++ compiler.

Make sure the Qt Widgets component is available in your Qt installation.

Step 2: Obtain the Project

Clone the private GitHub repository or download the project files provided by the team.

If cloning the repository, use:

git clone https://github.com/Ali-Abdelhamid100/Baby-Repository.git

Replace the placeholder with the actual repository URL.

Step 3: Open the Project

Open the project directory in Visual Studio Code or another development environment that supports CMake and Qt.

Step 4: Configure the Build

Make sure CMake can locate your Qt installation and that the selected compiler is compatible with it.

Configure the project using CMake and select the appropriate build kit or compiler.

Step 5: Build the Application

Build the "BabyPhotoshop" target using the development environment or CMake build tools.

If configuration or compilation fails, check the Qt installation path, compiler configuration, and required project files.

Step 6: Run the Application

After a successful build, launch the generated application from the development environment.

The application should open the Baby Photoshop graphical interface.

Note: The executable is generated during the local build process and should not be included in the submitted ZIP file.

7. How to Use the Application

1. Launch Baby Photoshop.
2. Open an image using the application's image-loading option.
3. Select the desired filter.
4. Adjust the available settings for that filter.
5. Apply the filter and preview the result.
6. Use Undo or Redo to navigate through supported editing history.
7. Use Reset Image to restore the original image, according to the application's implementation.
8. Save the edited image using the available saving options.

For filters that require a second image, such as Merge Images, provide the additional image when requested.

8. Saving Images

The application supports common image formats, including:

- PNG
- JPG
- JPEG
- BMP

Choose an appropriate file name and extension when saving an image.

The availability of individual formats depends on the application's implemented file-handling functionality and the image library.

9. Version Control

Git and GitHub were used for project collaboration and version control.

The team repository supports collaborative development, integration of individual filters, and project updates.

The repository should contain the source code and other required project files, excluding generated executable files from the final submission.

GitHub repository:
(https://github.com/Ali-Abdelhamid100/Baby-Repository.git)

10. Academic Information

Course: CS213 – Object Oriented Programming
Assignment: Assignment 1 – Baby Photoshop
Academic Year: 2026–2027
Faculty: Faculty of Computers and Artificial Intelligence, Cairo University
Supervisor: Dr. Mohammad El-Ramly

11. Notes

- Make sure all required source files are present before building the project.
- Use compatible versions of Qt, CMake, and the C++ compiler.
- Do not remove the required image-library files from the project.
- The final submission should contain the project source files and configuration files required by the assignment.
- Do not include executable files in the submitted ZIP archive.
- The demonstration video and shared project documentation should be provided separately or linked as required by the assignment.

---

Developed as part of the CS213 Object Oriented Programming course at FCAI, Cairo University.