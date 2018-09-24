#include "../VersionControl/version_control.h"

#include <gtest/gtest.h>

TEST(GoogleTestHW, gt_version_valid)
{
	ASSERT_GT(VersionControl::GetVersion(), 0);
}
