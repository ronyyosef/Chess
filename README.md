# Chess
Chess game with C++ and SFML for GUI

![Chess_demo (1)](https://user-images.githubusercontent.com/61323123/107888415-badce580-6f14-11eb-9bd1-70e1d9766bd0.gif)



# TO RUN THE CODE
download the RUN_ME folder and click on the chess.exe file


# future update:
- add castling
- add more mods


# structure:
- Game, this class manages the game flow.
- Board, this class manages all the checker.
- checker - this class controls a specific spot (row,col) on the board.
- Unit is a abstract class with two method:
      draw -  draw the unit on screen.
      get_possible_moves - get all the possible moves for a specific unit.
      King, Queen, Knight, Bishop, Rook, Pawn - all inherit from Unit.
      
  

  
