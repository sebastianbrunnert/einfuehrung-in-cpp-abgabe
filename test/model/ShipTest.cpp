#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../src/model/Ship.hpp"
#include "../../src/model/Constants.hpp"

TEST(ShipTest, Constructor) { 
    // Test valid ship creation
    EXPECT_NO_THROW(Ship ship(0, 5));
    EXPECT_NO_THROW(Ship ship(constants::VIEW_WIDTH - constants::SHIP_WIDTH, 3));
    
    // Test out of bounds position
    EXPECT_THROW(Ship ship(-1, 5), std::out_of_range);
    EXPECT_THROW(Ship ship(constants::VIEW_WIDTH - constants::SHIP_WIDTH + 1, 5), std::out_of_range);
    
    // Test negative lives
    EXPECT_THROW(Ship ship(0, -1), std::invalid_argument);
}

TEST(ShipTest, MoveLeft) {
    int startX = constants::SHIP_SPEED * 2;
    Ship ship(startX, 3);

    EXPECT_TRUE(ship.canMoveLeft());
    EXPECT_TRUE(ship.canMoveRight());

    // Move left within bounds
    ship.moveLeft();
    EXPECT_EQ(ship.getX(), startX - constants::SHIP_SPEED);

    EXPECT_TRUE(ship.canMoveLeft());
    EXPECT_TRUE(ship.canMoveRight());

    // Move left again
    ship.moveLeft();
    EXPECT_EQ(ship.getX(), startX - 2 * constants::SHIP_SPEED);

    EXPECT_FALSE(ship.canMoveLeft());
    EXPECT_TRUE(ship.canMoveRight());

    // Move left at the leftmost position
    ship.moveLeft();
    EXPECT_EQ(ship.getX(), startX - 2 * constants::SHIP_SPEED);

    EXPECT_FALSE(ship.canMoveLeft());
    EXPECT_TRUE(ship.canMoveRight());
}

TEST(ShipTest, MoveRight) {
    int startX = constants::VIEW_WIDTH - constants::SHIP_WIDTH - 2 * constants::SHIP_SPEED;
    Ship ship(startX, 3);

    EXPECT_TRUE(ship.canMoveLeft());
    EXPECT_TRUE(ship.canMoveRight());

    // Move right within bounds
    ship.moveRight();
    EXPECT_EQ(ship.getX(), startX + constants::SHIP_SPEED);

    EXPECT_TRUE(ship.canMoveLeft());
    EXPECT_TRUE(ship.canMoveRight());

    // Move right again
    ship.moveRight();
    EXPECT_EQ(ship.getX(), startX + 2 * constants::SHIP_SPEED);

    EXPECT_TRUE(ship.canMoveLeft());
    EXPECT_FALSE(ship.canMoveRight());

    // Move right at the rightmost position
    ship.moveRight();
    EXPECT_EQ(ship.getX(), startX + 2 * constants::SHIP_SPEED);

    EXPECT_TRUE(ship.canMoveLeft());
    EXPECT_FALSE(ship.canMoveRight());
}

TEST(ShipTest, TakeHit) {
    Ship ship(0, 3);

    // Take a hit and check lives
    ship.takeHit();
    EXPECT_EQ(ship.getLives(), 2);

    // Take another hit
    ship.takeHit();
    EXPECT_EQ(ship.getLives(), 1);

    // Take the last hit
    EXPECT_THROW(ship.takeHit(), std::runtime_error);
}
