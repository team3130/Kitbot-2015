# Kitbot-2015
The Robot built out of Kit Of Parts for Recycle Rush 2015 season

Installing OpenCV

Checkout the repository "2168_Vision_Example" from GitHub https://github.com/Team2168/2168_Vision_Example

Create a directory somewhere in your PC, for example and to keep all our robot projects consistant across
all the developers computers let's use the wpilib directory, hence create C:\Users\<your username>\wpilib\OpenCV
Copy the following directories from the 2168_Vision_Example repository into that directory

* 2168_Vision_Example\_Libraries\softFP\lib_cpp
* 2168_Vision_Example\_Libraries\softFP\lib_OpenCV

Also create a new directory in there (your new "wpilib\OpenCV" directory) and name it "include".
Copy the content of 2168_Vision_Example\_Includes\OpenCV\2.4.10 into that new "include" directory

That should work with already existing OpenCV testing projects.

Whenever you create a new robot project and are going to use OpenCV follow these steps:


