# Chess
Chess game with C++ and SFML for GUI

# TO RUN THE CODE
dowlond the RUN_ME folder and click on the chess.exe file


# future update:
- add castling
- add more mods


# structure:
- Game, this class manage the game flow.
- Board, this class manage all the checker.
- checker - this class control a specific spot (row,col) on the board.
- Unit is a abstract class with two method:
      draw -  draw the unit on screen.
      get_possible_moves - get all the possible moves for a specific unit.
      King, Queen, Knight, Bishop, Rook, Pawn all inherit from Unit.

  
