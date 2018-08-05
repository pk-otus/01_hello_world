#include "../VersionControl/version_control.h"

#include <gtest/gtest.h>

TEST(GoogleTestHW, gt_version_valid)
{
	ASSERT_GT(VersionControl::GetVersion(), 0);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
