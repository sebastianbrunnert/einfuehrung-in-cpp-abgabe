#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../src/model/Barrier.hpp"
#include "../../src/model/Constants.hpp"

TEST(BarrierTest, Constructor) {
    // Test valid barrier creation
    EXPECT_NO_THROW(Barrier barrier(0));
    EXPECT_NO_THROW(Barrier barrier(constants::VIEW_WIDTH - constants::BARRIER_WIDTH));

    // Test invalid barrier creation
    EXPECT_THROW(Barrier barrier(-1), std::out_of_range);
    EXPECT_THROW(Barrier barrier(constants::VIEW_WIDTH), std::out_of_range);
}

TEST(BarrierTest, Move) {
    Barrier barrier(constants::BARRIER_SPEED * 2);
    barrier.move();
    EXPECT_EQ(barrier.getX(), constants::BARRIER_SPEED);

    barrier.move();
    EXPECT_EQ(barrier.getX(), 0);

    // Now the direction should change
    barrier.move();
    EXPECT_EQ(barrier.getX(), constants::BARRIER_SPEED);
}