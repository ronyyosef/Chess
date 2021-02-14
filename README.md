# Chess
Chess game with C++ and SFML for GUI

<div style="width:360px;max-width:100%;"><div style="height:0;padding-bottom:80%;position:relative;"><iframe width="360" height="288" style="position:absolute;top:0;left:0;width:100%;height:100%;" frameBorder="0" src="https://imgflip.com/embed/4y19mh"></iframe></div><p><a href="https://imgflip.com/gif/4y19mh">via Imgflip</a></p></div>

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
      
  

  
