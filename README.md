# reStepper: It steps your steps when the steps you stepped weren't counted by your step counter. 

The future of fitness tracking is here! reStepper is an open-source, arduino-powered machine to walk your fitness tracker after those unfortunate workouts when your steps didn't get logged. Did you have the audacity to take you child for a walk in a stroller? Get those steps back! Were you foolish enough to go swimming when you could have walked in aimless circles around the pool? Don't let the credit drift away! Reckless enough to do something, anything, that might require you to take off your jewelry before working up a sweat? Let the reStepper sweat it all back! Maybe you just don't want third parties to know where you run, or where your secret morel patch is, or how fast they need to make the people harvesting machines in order to catch Charlton Heston. 

![The reStepper, an engineering marvel.](https://github.com/SouthernFriedScientist/reStepper/blob/master/images/reStepper.jpg)
*The reStepper, an engineering marvel.*

The reStepper uses a highly sophisticated algorithm to convert calories burned in a non-step-tacular workout into the steps you would have gotten burning those same calories on a light stroll. It works for both men and women thanks to a ridiculously oversized novelty toggle switch. 

## Are you serious?

I mean, not really, obviously (though the reStepper does work exactly as promised). This project exists for two reasons. 1. To push back against a trend towards quantifying everything we do by creating something ridiculous that does it better. And 2. Because this is a more fun way to learn to code in Arduino than just another "Blink LED" tutorial. Building a reStepper will teach you how to read digital rotary encoders and binary switches, output to an LCD, and control a servo. You'll create a basic user interface that takes two forms of inputs and converts that into actions through an algorithm you can tinker with and tune. Use your own fitness tracking data to create a machine custom built for your own activity levels.

And when it starts swinging for the first time, you won't stop laughing.

If you want to add some blinking LEDs, there's plenty of room for that, too. 

## Bill of Materials

Note: I use Amazon Affiliate links because the small kickback helps me fund more projects like this, but almost everything can be sourced directly through [Adafruit](https://www.adafruit.com/) as well. Some of the items are explicitly necessary (you can use a standard mini-breadboard if you don't want to solder) and some only come in batches, so shop around first. These recommendations don't represent the cheapest prices. 

|Item|Price|Link|Notes|
---|---|---|---|
|Adafruit METRO 328 | $25.00 | https://amzn.to/2SClIu0 | the brain |
|Adafruit Assembled Standard LCD 16x2 | $16.95 | https://amzn.to/2VyTzWH | to see your outputs |
|Small Solderable Breadboard | $9.58 | https://amzn.to/2SA075C | to make some basic circuits |
|Adafruit Accessories Rotary Encoder | $8.20 | https://amzn.to/2AvwQSw | your primary input |
|Adafruit Solid Machined Metal Knob | $ 9.11 | https://amzn.to/2SK7yr2 | this is not necessary, but looks nice |
|Push button switch | $7.29 | https://amzn.to/2C8t15U | I have a bag of these for random projects |
|Momentary switch | $6.68 | https://amzn.to/2LSACcX | shop around, you want a little one that is normally open |
|Toggle Switch | $8.56 | https://amzn.to/2SAGCJT | 3-pins, 2 positions, find the most obnoxiously oversized one you can |
|Adafruit Towerpro Servo | $21.57 | https://amzn.to/2SDxJzu | shape file fits this specific servo, no others were tested |
|Power Supply | $8.99 | https://amzn.to/2RB9nsP | Unless you only want to run it off USB |
|4lb soft dive weight | $19.95 | https://amzn.to/2LUW7tZ | to keep it from shaking off the table |
| M3 Stainless Steel Nuts and Bolts | $10.99 | https://amzn.to/2LTsiKd | this little kit will see you through dozens of maker projects |
| M5 Stainless Steel Nuts, Washers, Bolts, and Lock Nuts | - | - | you're better off getting these from your local hardware store |

In addition, you'll want a basic set of jumper wires, some extra wire to connect up the servo, a 10K resistor, and if your LCD doesn't come with a pot resistor, you'll need on of those too. You'll also want a good soldering iron (though you can get away with just jumper wires and breadboards if you want). I also added some little rubber feet. 

For the acrylic, you'll need access to a lasercutter. Check with your local makerspace, or, I guess, buy a Glowforge (seriously, if you do, please use my affiliate link for that: https://amzn.to/2RussNm). I use regular old cyanoacrylate "Super Glue" and just lightly hotglued the back panel of the base just in case I needed to get back in. 

## Build Guide

This is a fairly straightforward build that can easily be completed in an afternoon with only basic electronics skills. If you're new to arduino, this might just be the right project to learn on. Always dry fit every piece before you glue. 

The 6mm components are all joined together with M3 bolts and nuts and the holes are lined up such that each part can only be mated to its correct opposite. 3mm support pieces are used to sandwich in the 3mm struts (no glue is required). THe spine of the long piece is glued to the center of the forked bar. THe entire arm assembly is slotted into the base and glued in place to both the top and bottom base pieces. The "bearings" of the swing arm are held in by an M4 bolt with a nut and washer sandwiching the center piece and a locking nut and washer holding in the back. 

The bolt supporting the swingarm on the power head is sandwiched in place with a luckint nut, washer, and standard nut. 

Please refer to the following images:

![Support arch above the powerhead.](https://github.com/SouthernFriedScientist/reStepper/blob/master/images/powerhead_top.jpg)
*Support arch above the powerhead.*

![Load-bearing bolt that supports the swingarm at the servo junction.](https://github.com/SouthernFriedScientist/reStepper/blob/master/images/swingarm_join.jpg)
*Load-bearing bolt that supports the swingarm at the servo junction.*

![Servo bolted to powerhead.](https://github.com/SouthernFriedScientist/reStepper/blob/master/images/powerhead_servo.jpg)
*Servo bolted to powerhead.*

![Powerhead bolted to main strut.](https://github.com/SouthernFriedScientist/reStepper/blob/master/images/powerhead_strut.jpg)
*Powerhead bolted to main strut.*

![Support spine top joint.](https://github.com/SouthernFriedScientist/reStepper/blob/master/images/spine_top.jpg)
*Support spine top joint.*

![Main strut and support spine.](https://github.com/SouthernFriedScientist/reStepper/blob/master/images/strut_middle.jpg)
*Main strut and support spine.*

![Swing arm upper hinge.](https://github.com/SouthernFriedScientist/reStepper/blob/master/images/swingarm_hinge.jpg)
*Swing arm upper hinge.*

![Swing arm lower hinge.](https://github.com/SouthernFriedScientist/reStepper/blob/master/images/swingarm_lower.jpg)
*Swing arm lower hinge.*

![Bottom of the base plate with strut and spine pass through.](https://github.com/SouthernFriedScientist/reStepper/blob/master/images/base_bottom.jpg)
*Bottom of the base plate with strut and spine pass through.*

## FAQ Link

[I built an open-source robot that steps your steps when the steps you stepped weren’t counted by your step counter: Frequently Asked Questions.](http://www.southernfriedscience.com/i-built-an-open-source-robot-that-steps-your-steps-when-the-steps-you-stepped-werent-counted-by-your-step-counter-frequently-asked-questions/)

## Acknowledgements

Developed by [Andrew Thaler](https://twitter.com/DrAndrewThaler). Special thanks to [Amy Freitag](https://twitter.com/bgrassbluecrab), [David Shiffman](https://twitter.com/WhySharksMatter), [Jake Levenson](https://twitter.com/JacobLevenson), and all the folks in my FitBit Workweek Challenge who are super annoyed right about now. 

Please visit my [Patreon page](https://www.patreon.com/Andrew_Thaler) to support more weird and wonderful projects like this. 
