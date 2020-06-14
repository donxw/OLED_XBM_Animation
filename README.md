# OLED_XBM_Animation
Basic example to animate images on an OLED screen using an Arduino compatible board

## Parts
* Heltec WifiKit8 with build in OLED
* GIMP drawing software

## Abstract
This project documents how to do a very basic animation on using an arduino compatible board and and OLED screen.  It describes how to set up GIMP for Pixel Art, exporting to an XBM file and then how to use the XBM display capability of the U8g2 library.

This example is heavily leveraged from this site:  https://www.hackster.io/138689/pixel-art-on-oled-display-7f8697#code - Go there for in depth explainations.

Changes made are to accomdate using GIMP and to use a matrix to hold all frames.

## Making the animation frame images
GIMP has very good support for XBM file reading and writing.  It is also very will supported with tutorials which can be found with a quick web search.  

*Set up GIMP for Pixel Art*
1. - File / New 
2. - Change Image Size to 32 x 32
3. - View / Zoom / Fit Image in Window
4. - Edit / Preferences / Default Grid / 1 Horizontal / 1 Vertical
5. - View / Show Grid
6. - Image / Mode / Indexed / Use black and white (1-bit) palette, click Convert (Keep Dithering to None)
7. - Type "N" to go to pencil mode
8. - Change size in pencil properties to 1
9. - Save this as a template - File / Create Template

### Create your first frame

Create a drawing of your own as your first frame.  To create the second frame start a new 32x32 file using the Pixel Art template above.  Copy the original image (Edit / Copy Visible).  To to the new blank frame and paste (Edit / Paste in place). Make small alterations to represent the second animation frame.  Repeat for as many frames as you need.

### Sample First Frame









