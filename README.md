# OLED_XBM_Animation
Basic example to animate images on an OLED screen using an Arduino compatible board

## Parts
* Heltec WifiKit8 with build in OLED
* GIMP drawing software
* Notepad++

## Abstract
This project documents how to do a very basic animation on using an arduino compatible board and and OLED screen.  It describes how to set up GIMP for Pixel Art, exporting to an XBM file and then how to use the XBM display capability of the U8g2 library.

This example is heavily leveraged from this site:  https://www.hackster.io/138689/pixel-art-on-oled-display-7f8697#code - Go there for in depth explanations.

GIMP was used to create the images and export to XBM.

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

Create a pixel drawing as a first frame.  To create the second frame start a new 32x32 file using the Pixel Art template above.  Copy the original image (Edit / Copy Visible).  To to the new blank frame and paste (Edit / Paste in place). Make small alterations to represent the second animation frame.  Repeat for as many frames as you need.

### Sample First Frame

![FirstFrame (Small)](https://user-images.githubusercontent.com/31633408/84603493-bb802200-ae43-11ea-8c71-32afef912d5a.png)

For this project, three frames were enough.  Each frame incrementally changes to look like a blink.

![AllThreeFrames](https://user-images.githubusercontent.com/31633408/84603592-54af3880-ae44-11ea-9207-947b74cebab4.png)

### Export to XBM format

Use File / Export As / Select File Type (by Extension) / X Bitmap Image.  Accept the defaults and click Export.  





