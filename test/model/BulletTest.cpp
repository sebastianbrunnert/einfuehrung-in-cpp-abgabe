#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../src/model/Bullet.hpp"
#include "../../src/model/Constants.hpp"

TEST(BulletTest, Constructor) { 
    // Test valid bullet creation
    EXPECT_NO_THROW(Bullet bullet(0, 0, false));
    EXPECT_NO_THROW(Bullet bullet(100, 100, true));

    // Test invalid bullet creation
    EXPECT_THROW(Bullet bullet(10, -1, false), std::out_of_range);
    EXPECT_THROW(Bullet bullet(-1, 10, true), std::out_of_range);
    EXPECT_THROW(Bullet bullet(constants::VIEW_HEIGHT+1, 10, false), std::out_of_range);
    EXPECT_THROW(Bullet bullet(-1, constants::VIEW_WIDTH+1, true), std::out_of_range);
}

TEST(BulletTest, Update) {
    // Update bullet position
    Bullet bullet(0, 2 * constants::BULLET_SPEED, false);
    bullet.update();
    EXPECT_EQ(bullet.getY(), constants::BULLET_SPEED);

    // Update bullet again
    bullet.update();
    EXPECT_EQ(bullet.getY(), 0);

    // Update bullet at the bounds of the screen
    bullet.update();
    EXPECT_TRUE(bullet.isOutOfBounds());

    // Same for alien bullet
    Bullet alienBullet(0, constants::VIEW_HEIGHT - 2 * constants::BULLET_SPEED, true);
    alienBullet.update();
    EXPECT_EQ(alienBullet.getY(), constants::VIEW_HEIGHT - constants::BULLET_SPEED);

    // Update alien bullet again
    alienBullet.update();
    EXPECT_EQ(alienBullet.getY(), constants::VIEW_HEIGHT);

    // Update alien bullet at the bounds of the screen
    alienBullet.update();
    EXPECT_TRUE(alienBullet.isOutOfBounds());
}

TEST(BulletTest, Equal) {
    Bullet bullet1(0, 0, false);
    Bullet bullet2(0, 0, false);

    EXPECT_TRUE(bullet1 == bullet1);
    EXPECT_FALSE(bullet1 == bullet2);
}

TEST(BulletTest, CollidesWithAlien) {
    Bullet alien_bullet(0, 0, true);
    Bullet bullet(0, 0, false);
    Alien alien1(0, 0);
    Alien alien2(constants::BULLET_WIDTH-1, 0);
    Alien alien3(constants::BULLET_WIDTH, 0);
    Alien alien4(constants::BULLET_WIDTH+1, 0);

    EXPECT_FALSE(alien_bullet.collidesWithAlien(alien1));
    EXPECT_TRUE(bullet.collidesWithAlien(alien1));
    EXPECT_TRUE(bullet.collidesWithAlien(alien2));
    EXPECT_FALSE(bullet.collidesWithAlien(alien3));
    EXPECT_FALSE(bullet.collidesWithAlien(alien4));
}

TEST(BulletTest, CollidesWithShip) {
    Bullet ship_bullet(0, 0, false);
    Bullet bullet1(0, constants::SHIP_Y, true);
    Bullet bullet2(0, constants::SHIP_Y - constants::BULLET_HEIGHT, true);
    Ship ship1(0, 0);
    Ship ship2(constants::BULLET_WIDTH-1, 0);
    Ship ship3(constants::BULLET_WIDTH, 0);
    Ship ship4(constants::BULLET_WIDTH+1, 0);

    EXPECT_FALSE(ship_bullet.collidesWithShip(ship1));
    EXPECT_TRUE(bullet1.collidesWithShip(ship1));
    EXPECT_TRUE(bullet1.collidesWithShip(ship2));
    EXPECT_FALSE(bullet1.collidesWithShip(ship3));
    EXPECT_FALSE(bullet1.collidesWithShip(ship4));
    EXPECT_FALSE(bullet2.collidesWithShip(ship1));
    EXPECT_FALSE(bullet2.collidesWithShip(ship2));
}