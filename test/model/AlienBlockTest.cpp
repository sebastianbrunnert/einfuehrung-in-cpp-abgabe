#include <gtest/gtest.h>
#include "../../src/model/Constants.hpp"
#include "../../src/model/AlienBlock.hpp"

TEST(AlienBlockTest, Constructor) {
    AlienBlock block;

    // 5 rows * 10 columns = 50 aliens
    EXPECT_EQ(block.getAliens().size(), 50);

    // Check positions of some aliens
    const auto& aliens = block.getAliens();
    EXPECT_EQ(aliens[0].getX(), 0);
    EXPECT_EQ(aliens[0].getY(), constants::ALIEN_RADIUS*2 + constants::ALIEN_GAP);
    
    EXPECT_EQ(aliens[1].getX(), constants::ALIEN_RADIUS * 2 + constants::ALIEN_GAP);
    EXPECT_EQ(aliens[1].getY(), constants::ALIEN_RADIUS*2 + constants::ALIEN_GAP);

    EXPECT_EQ(aliens[10].getX(), 0);
    EXPECT_EQ(aliens[10].getY(), constants::ALIEN_RADIUS * 4 + constants::ALIEN_GAP * 2);
}

TEST(AlienBlockTest, Move) {
    AlienBlock block;

    block.move();
    const auto& aliens = block.getAliens();

    EXPECT_EQ(aliens[0].getX(), constants::ALIEN_GAP);
    EXPECT_EQ(aliens[0].getY(), constants::ALIEN_RADIUS*2 + constants::ALIEN_GAP);

    EXPECT_EQ(aliens[1].getX(), constants::ALIEN_RADIUS * 2 + 2 * constants::ALIEN_GAP);
    EXPECT_EQ(aliens[1].getY(), constants::ALIEN_RADIUS*2 + constants::ALIEN_GAP);

    EXPECT_EQ(aliens[10].getX(), constants::ALIEN_GAP);
    EXPECT_EQ(aliens[10].getY(), constants::ALIEN_RADIUS * 4 + constants::ALIEN_GAP * 2);
}

TEST(AlienBlockTest, MoveMultiple) {
    AlienBlock block;

    const auto& aliens = block.getAliens();
    int xBefore = aliens[0].getX();

    bool changedDirection = false;

    // Try maximum 1000 times
    for(int i = 0; i < 1000; i++) {
        block.move();

        if(aliens[0].getX() < xBefore) {
            changedDirection = true;
            break;   
        }

        xBefore = aliens[0].getX();
    }

    EXPECT_TRUE(changedDirection) << "Aliens did not change direction after moving right multiple times";
}