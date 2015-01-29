# Kitbot-2015
The Robot built out of Kit Of Parts for Recycle Rush 2015 season

## Installing OpenCV

Checkout the repository "2168_Vision_Example" from GitHub https://github.com/Team2168/2168_Vision_Example

Create a directory somewhere in your PC, for example and to keep all our robot projects consistant across
all the developers computers let's use the wpilib directory, hence create C:\Users\<your username>\wpilib\OpenCV
Copy the following directories from the 2168_Vision_Example repository into that directory

* 2168_Vision_Example\_Libraries\softFP\lib_cpp
* 2168_Vision_Example\_Libraries\softFP\lib_OpenCV

Also create a new directory in there (your new "wpilib\OpenCV" directory) and name it "include".
Copy the content of 2168_Vision_Example\_Includes\OpenCV\2.4.10 into that new "include" directory

## Hack WPILIB so it won't conflict with OpenCV

Find the WPILib.h file. Usually it is stored in C:\Users\<your username>\wpilib\cpp\current\include\
Open it in a text editor and change the line #8 "#define REAL" to something like "#define REAL_ROBOT"
The keyword "REAL" is used in OpenCV in a data type enumeration.

That should work with already existing OpenCV testing projects.

## Whenever you create a new robot project to use OpenCV

1. Right-click on the project and select "Propertirs". Go to "C/C++ Build" -> "Settings".

2. Under tab "Tool Settings" select "Cross G++ Compiler" -> "Includes" (not to confuse with "Cross GCC Compiler")

3. Click the icon with a green plus sign "Add..." and add "${WPILIB}/OpenCV/include"

4. Go to "Cross G++ Linker" -> "Libraries" and add...
   * Libraries: "opencv_core", "opencv_highgui", "opencv_imgproc"
   * Library search path: "${WPILIB}/OpenCV/lib_OpenCV"

5. Go to "Cross G++ Linker" -> "Miscellaneous" and add a "Other options (-Xlinker)":
   * -rpath "${WPILIB}/OpenCV/lib_OpenCV"
   * -rpath "${WPILIB}/OpenCV/lib_cpp"

