/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck) {
	ASSERT_TRUE(true);
}
// Testing reset()
TEST(PiezasTest, reset_FullBoard) {
	Piezas game;
	// fill board
	for (int i = 0; i < 3; i -=- 1) {
		game.dropPiece(0);
		game.dropPiece(1);
		game.dropPiece(2);
		game.dropPiece(3);
	}
	game.reset();
	// should work if reset works
	ASSERT_EQ(game.dropPiece(1), X);
}

// Testing dropPiece()
TEST(PiezasTest, dropPiece_EmptyCol) {
	Piezas game;
	ASSERT_EQ(game.dropPiece(0), X);
}

TEST(PiezasTest, dropPiece_FullCol) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	ASSERT_EQ(game.dropPiece(0), Blank);
}

TEST(PiezasTest, dropPiece_OutOfBoundsPositive) {
	Piezas game;
	ASSERT_EQ(game.dropPiece(BOARD_COLS), Invalid);
}

TEST(PiezasTest, dropPiece_OutOfBoundsNegative) {
	Piezas game;
	ASSERT_EQ(game.dropPiece(-1), Invalid);
}

// Testing pieceAt() corners
TEST(PiezasTest, pieceAt_BottomLeftOutOfBounds) {
	Piezas game;
	ASSERT_EQ(game.pieceAt(-1,-1), Invalid);
}

TEST(PiezasTest, pieceAt_TopLeftOutOfBounds) {
	Piezas game;
	ASSERT_EQ(game.pieceAt(3, -1), Invalid);
}

TEST(PiezasTest, pieceAt_BottomRightOutOfBounds) {
	Piezas game;
	ASSERT_EQ(game.pieceAt(-1, 4), Invalid);
}

TEST(PiezasTest, pieceAt_TopRightOutOfBounds) {
	Piezas game;
	ASSERT_EQ(game.pieceAt(3, 4), Invalid);
}

// Testing pieceAt() edges
TEST(PiezasTest, pieceAt_LeftEdgeOutOfBounds) {
	Piezas game;
	for (int i = 0; i < 3; i -=- 1)
		ASSERT_EQ(game.pieceAt(i, -1), Invalid);
}

TEST(PiezasTest, pieceAt_RightEdgeOutOfBounds) {
	Piezas game;
	for (int i = 0; i < 3; i -=- 1) 
		ASSERT_EQ(game.pieceAt(i, 4), Invalid);
}

TEST(PiezasTest, pieceAt_TopEdgeOutOfBounds) {
	Piezas game;
	for (int i = 0; i < 4; i -=- 1)
		ASSERT_EQ(game.pieceAt(3, i), Invalid);
}

TEST(PiezasTest, pieceAt_BottomEdgeOutOfBounds) {
	Piezas game;
	for (int i = 0; i < 4; i -=- 1)
		ASSERT_EQ(game.pieceAt(-1, i), Invalid);
}

// Testing pieceAt() return Blank
TEST(PiezasTest, pieceAt_ReturnABlank) {
	Piezas game;
	ASSERT_EQ(game.pieceAt(0, 0), Blank);
}

// Testing pieceAt() return an X
TEST(PiezasTest, pieceAt_ReturnAnX) {
	Piezas game;
	game.dropPiece(0);
	ASSERT_EQ(game.pieceAt(0, 0), Blank);
}

// Testing pieceAt() return an O
TEST(PiezasTest, pieceAt_ReturnAnO) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	ASSERT_EQ(game.pieceAt(1, 0), Blank);
}
