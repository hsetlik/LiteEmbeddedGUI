# LiteEmbeddedGUI

## Window/ display class

### Tasks

- Render top level component as texture
- Poll user inputs/ run callbacks
- Keep track of frame rates

 ### Main function

`run()` function gets called in main.cpp. Should work like

1. check events and run callbacks
2. IF it's time for a new frame, render the new frame