#include "BlackPawn.h"
#include "Chess.h"
#include "King.h"
#include "Rook.h"
#include "TestCode.h"
#include "WhitePawn.h"
#include <iostream>

void TestCode::testPawns() 
{
  // Create a chessboard
  Chess::createBoard();

  // Test print board
  std::cout << "Testing print empty board:" << std::endl;
  Chess::printBoard();

  // Test creating pawns
  std::cout << "Testing creating pawns (black pawns shoudl fill rank 7 and white pawns should fill rank 2):" << std::endl;
  WhitePawn P1('a', 2);
  WhitePawn P2('b', 2);
  WhitePawn P3('c', 2);
  WhitePawn P4('d', 2);
  WhitePawn P5('e', 2);
  WhitePawn P6('f', 2);
  WhitePawn P7('g', 2);
  WhitePawn P8('h', 2);
  BlackPawn p1('a', 7);
  BlackPawn p2('b', 7);
  BlackPawn p3('c', 7);
  BlackPawn p4('d', 7);
  BlackPawn p5('e', 7);
  BlackPawn p6('f', 7);
  BlackPawn p7('g', 7);
  BlackPawn p8('h', 7);
  Chess::printBoard();

  // Test move forward 2
  std::cout << "Testing moving forward 2 (a2 and b2 should move to a4 and b4 respectively; a7 and b7 should move to a5 and b5 respectively):" << std::endl;
  P1.move('a', 4);
  p1.move('a', 5);
  P2.move('b', 4);
  p2.move('b', 5);
  Chess::printBoard();

  // Test capturing opponent pawn
  std::cout << "Testing capturing opponent pawn (a4 should capture b5, and a5 should capture b4):" << std::endl;
  P1.move('b', 5);
  p1.move('b', 4);
  Chess::printBoard();

  // Test move forward 1
  std::cout << "Testing move forward 1 (b5 should move to b6 and b4 should move to b3):" << std::endl;
  P1.move('b', 6);
  p1.move('b', 3);
  Chess::printBoard();

  // Test move forward two after first move
  std::cout << "Testing move forward 2 after first try (should see no move):" << std::endl;
  P1.move('b', 8);
  p1.move('b', 1);
  Chess::printBoard();

  // Test move forward more than two
  std::cout << "Testing move forward more than two (should see no move):" << std::endl;
  P3.move('c', 5);
  p4.move('d', 4);
  Chess::printBoard();

  // Test move backward
  std::cout << "Testing moving backward(should see no move):" << std::endl;
  P1.move('b', 5);
  p2.move('b', 2);
  Chess::printBoard();

  // Test moving left or right
  std::cout << "Testing moving left or right (should see no move):" << std::endl;
  P1.move('a', 6);
  p2.move('c', 3);
  Chess::printBoard();

  // Test moving past end of board
  std::cout << "Testing moving past end of board (b6 should move to b8 and b3 should move to b1):" << std::endl;
  P1.move('b', 7);
  P1.move('b', 8);
  P1.move('b', 9);
  p1.move('b', 2);
  p1.move('b', 1);
  p1.move('b', 0);
  Chess::printBoard();
}

void TestCode::testRooks() 
{
  // Create a chessboard
  Chess::createBoard();

  // Test print board
  std::cout << "Testing print empty board:" << std::endl;
  Chess::printBoard();

  // Test creating Rooks
  std::cout << "Testing creating rooks (rooks should appear at a1, h1, a8, and h8)" << std::endl;
  Rook R1('R', 'a', 1);
  Rook R2('R', 'h', 1);
  Rook r1('r', 'a', 8);
  Rook r2('r', 'h', 8);
  Chess::printBoard();

  // Test moving rooks vertically
  std::cout << "Testing moving rooks vertically (a1 should move to a4, a8 should move to a5, h1 should move to h3 and h8 should move to h4)" << std::endl;
  R1.move('a', 4);
  r1.move('a', 5);
  R2.move('h', 3);
  r2.move('h', 4);
  Chess::printBoard();

  // Test moving rooks horizontally
  std::cout << "Testing moving rooks horizontally (a4 should move to f4, h4 should move to g4, a5 shoudl move to h5, and h3 should move to a3)" << std::endl;
  R1.move('f', 4);
  r1.move('h', 5);
  R2.move('a', 3);
  r2.move('g', 4);
  Chess::printBoard();

  // Test running over obstacles
  std::cout << "Testing running over obstacles (should see no change except for pawn obstacles appearing at a5 and h3)" << std::endl;
  R1.move('h', 4); // move up in file
  r2.move('e', 4); // move down in file
  WhitePawn P1('h',3);
  BlackPawn p1('a', 5);
  R2.move('a',8); // move up in rank
  r1.move('h',1); // move down in rank
  Chess::printBoard();

  // Test capturing opposite colored pawns
  std::cout << "Testing capturing opposite colored pawns (should see a3 capture a5 and h5 capture h3)" << std::endl;
  R2.move('a',5);
  r1.move('h',3);
  Chess::printBoard();

  // Test capturing same colored pawns
  std::cout << "Testing capturing same colored pawns (should see no change except for new pawns appearing at a4 and h4)" << std::endl;
  WhitePawn P2('a',4);
  BlackPawn p2('h', 4);
  R2.move('a',4);
  r1.move('h',4);
  Chess::printBoard();
}

void TestCode::testKings() 
{
  // Create a chessboard
  Chess::createBoard();

  // Test print board
  std::cout << "Testing print empty board:" << std::endl;
  Chess::printBoard();

  // Test creating kings
  std::cout << "Creating Kings (should show up at e1 and e8)" << std::endl;
  King K1('K', 'e', 1);
  King k1 ('k', 'e', 8);
  Chess::printBoard();

  // Test move once in each dirction
  std::cout << "Testing move once in each dirction(e1 should end up in f1 and e8 should end up in f8)" << std::endl;
  K1.move('d', 1);
  K1.move('d', 2);
  K1.move('e', 2);
  K1.move('f', 2);
  K1.move('f', 1);
  k1.move('d', 8);
  k1.move('d', 7);
  k1.move('e', 7);
  k1.move('f', 7);
  k1.move('f', 8);
  Chess::printBoard();

  // Test move more than one square
  std::cout << "Testing move more than one square (should see no change)" << std::endl;
  K1.move('a', 1);
  K1.move('a', 2);
  K1.move('a', 3);
  K1.move('a', 4);
  K1.move('a', 5);
  K1.move('a', 6);
  K1.move('a', 7);
  K1.move('a', 8);
  K1.move('b', 1);
  K1.move('b', 2);
  K1.move('b', 3);
  K1.move('b', 4);
  K1.move('b', 5);
  K1.move('b', 6);
  K1.move('b', 7);
  K1.move('b', 8);
  K1.move('c', 1);
  K1.move('c', 2);
  K1.move('c', 3);
  K1.move('c', 4);
  K1.move('c', 5);
  K1.move('c', 6);
  K1.move('c', 7);
  K1.move('c', 8);
  K1.move('d', 1);
  K1.move('d', 2);
  K1.move('d', 3);
  K1.move('d', 4);
  K1.move('d', 5);
  K1.move('d', 6);
  K1.move('d', 7);
  K1.move('d', 8);
  K1.move('e', 3);
  K1.move('e', 4);
  K1.move('e', 5);
  K1.move('e', 6);
  K1.move('e', 7);
  K1.move('e', 8);
  K1.move('f', 3);
  K1.move('f', 4);
  K1.move('f', 5);
  K1.move('f', 6);
  K1.move('f', 7);
  K1.move('f', 8);
  K1.move('g', 3);
  K1.move('g', 4);
  K1.move('g', 5);
  K1.move('g', 6);
  K1.move('g', 7);
  K1.move('g', 8);
  K1.move('h', 1);
  K1.move('h', 2);
  K1.move('h', 3);
  K1.move('h', 4);
  K1.move('h', 5);
  K1.move('h', 6);
  K1.move('h', 7);
  K1.move('h', 8);
  Chess::printBoard();

  // Test capturing opposite colored pawns
  std::cout << "Testing capturing opposite colored pawns (pawns appear in f7, g7, f2, g2. f1 captures f2 and f8 captures f7) " << std::endl;
  WhitePawn P3('e', 2);
  BlackPawn p3('f', 2);
  WhitePawn P4('f', 7);
  BlackPawn p4('g', 7);
  K1.move('f', 2);
  k1.move('f', 7);
  Chess::printBoard();

  // Test capturing same colored pawns
  std::cout << "Testing capturing same colored pawns (should see no change)" << std::endl;
  K1.move('e', 2);
  k1.move('g', 7);
  Chess::printBoard();
}




