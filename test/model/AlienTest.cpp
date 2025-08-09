#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../src/model/Alien.hpp"
#include "../../src/model/Constants.hpp"

TEST(AlienTest, Constructor) { 
    // Test valid alien creation
    EXPECT_NO_THROW(Alien alien(0, 0));
    EXPECT_NO_THROW(Alien alien(constants::VIEW_WIDTH - constants::ALIEN_RADIUS * 2, constants::VIEW_HEIGHT - constants::ALIEN_RADIUS * 2));

    // Test invalid alien creation
    EXPECT_THROW(Alien alien(-1, 0), std::out_of_range);
    EXPECT_THROW(Alien alien(0, -1), std::out_of_range);
    EXPECT_THROW(Alien alien(constants::VIEW_WIDTH - constants::ALIEN_RADIUS * 2 + 5, 10), std::out_of_range);
    EXPECT_THROW(Alien alien(10, constants::VIEW_HEIGHT - constants::ALIEN_RADIUS * 2 + 5), std::out_of_range);
}

TEST(AlienTest, MoveLeft) {
    Alien alien(constants::ALIEN_GAP * 2, 0);

    EXPECT_TRUE(alien.canMoveLeft());
    EXPECT_TRUE(alien.canMoveRight());

    // Move left within bounds
    EXPECT_NO_THROW(alien.moveLeft());
    EXPECT_EQ(alien.getX(), constants::ALIEN_GAP);

    EXPECT_TRUE(alien.canMoveLeft());
    EXPECT_TRUE(alien.canMoveRight());

    // Move left again
    EXPECT_NO_THROW(alien.moveLeft());
    EXPECT_EQ(alien.getX(), 0);

    EXPECT_FALSE(alien.canMoveLeft());
    EXPECT_TRUE(alien.canMoveRight());

    // Move left at the leftmost position
    EXPECT_THROW(alien.moveLeft(), std::out_of_range);
}

TEST(AlienTest, MoveRight) {
    int startX = constants::VIEW_WIDTH - constants::ALIEN_RADIUS * 2 - constants::ALIEN_GAP * 2;
    Alien alien(startX, 0);

    EXPECT_TRUE(alien.canMoveLeft());
    EXPECT_TRUE(alien.canMoveRight());

    // Move right within bounds
    EXPECT_NO_THROW(alien.moveRight());
    EXPECT_EQ(alien.getX(), startX + constants::ALIEN_GAP);

    EXPECT_TRUE(alien.canMoveLeft());
    EXPECT_TRUE(alien.canMoveRight());

    // Move right again
    EXPECT_NO_THROW(alien.moveRight());
    EXPECT_EQ(alien.getX(), startX + constants::ALIEN_GAP * 2);

    EXPECT_FALSE(alien.canMoveRight());
    EXPECT_TRUE(alien.canMoveLeft());

    // Move right at the rightmost position
    EXPECT_THROW(alien.moveRight(), std::out_of_range);

    EXPECT_EQ(alien.getX(), startX + constants::ALIEN_GAP * 2);
    EXPECT_TRUE(alien.canMoveLeft());
    EXPECT_FALSE(alien.canMoveRight());
}

TEST(AlienTest, MoveDown) {
    int startY = constants::VIEW_HEIGHT - constants::ALIEN_RADIUS * 6 - constants::ALIEN_GAP * 3;
    Alien alien(100, startY);

    EXPECT_TRUE(alien.canMoveDown());

    // Move down within bounds
    alien.moveDown();
    EXPECT_EQ(alien.getY(), startY + constants::ALIEN_GAP + constants::ALIEN_RADIUS * 2);

    EXPECT_TRUE(alien.canMoveDown());

    // Move down again
    alien.moveDown();
    EXPECT_EQ(alien.getY(), startY + 2 * (constants::ALIEN_GAP + constants::ALIEN_RADIUS * 2));

    EXPECT_FALSE(alien.canMoveDown());

    // Move down at the bottommost position
    EXPECT_THROW(alien.moveDown(), std::out_of_range);

    EXPECT_EQ(alien.getY(), startY + 2 * (constants::ALIEN_GAP + constants::ALIEN_RADIUS * 2));
    EXPECT_FALSE(alien.canMoveDown());
}

TEST(AlienTest, Equal) {
    Alien alien1(0, 0);
    Alien alien2(0, 0);

    EXPECT_TRUE(alien1 == alien1);
    EXPECT_FALSE(alien1 == alien2);
}