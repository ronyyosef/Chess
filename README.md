# Chess
Chess game with C++ and SFML for GUI

<video width="320" height="240" controls>
  <source src="https://user-images.githubusercontent.com/61323123/107888248-b663fd00-6f13-11eb-8a68-e8f00e7990a6.mp4" type="video/mp4">
  Your browser does not support the video tag.
</video>

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
      
  

  
