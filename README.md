# Interactive Chessboard Project

This project was developed by Yurevych Nataliia and Dmytro Shumskyi, under the mentorship of Oleksii Hoev. The interactive chessboard is designed to enhance the learning experience for chess players by visually highlighting all possible moves when a piece is picked up, including red lighting to indicate potential captures.

## Overview

The chessboard is equipped with Hall sensors and magnets to track the movement of chess pieces. By lifting a piece, the board immediately lights up to show all legal moves, providing both guidance for beginners and an engaging experience for seasoned players. Red lighting specifically marks moves where an opponent’s piece can be captured.

## Features

- **Move Highlighting**: Shows all possible moves upon picking up a piece.
- **Capture Indication**: Red lighting highlights squares where an opponent’s piece can be captured.
- **False Move Processing**: Under development, with examples shown in project videos.
  
## Design & Construction

The board and pieces were designed in Autodesk Fusion 360, and the build process included:

- **Materials**: Constructed from plywood, acrylic glass, and 3D-printed partitions.
- **LED Lighting**: The upper layer of the board contains LED strips for move highlighting.
- **Sensor Array**: Hall sensors with intertwined resistors form the lower layer, reducing space requirements.
  
## Hardware

- **Hall Sensors and Magnets**: Track piece movements accurately.
- **Multiplexers (74HC151)**: Reduce the number of necessary pins.
- **Arduino MEGA**: Processes signals from sensors to control lighting.

## Acknowledgments

Thanks to Oleksii Hoev for his mentorship and hands-on help, as well as people who assisted with the 3D printing.
