#include <gtest/gtest.h>
#include "worker.h" // Assuming the program is in worker.h

TEST(WorkerTest, CustomerSupporter)
{
    CEO ceo(nullptr);
    SoftwareEngineer se(&ceo);
    CustomerSupporter supporter(&se);

    testing::internal::CaptureStdout(); // Capture stdout
    supporter.Work(Task::CustomerIssue);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("[CustomerSupporter] Resolve customer issue."), std::string::npos);
}

TEST(WorkerTest, SoftwareEngineer)
{
    CEO ceo(nullptr);
    SoftwareEngineer se(&ceo);
    CustomerSupporter supporter(&se);

    testing::internal::CaptureStdout(); // Capture stdout
    supporter.Work(Task::Programming);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("[SoftwareEngineer] Programming."), std::string::npos);
}

TEST(WorkerTest, HardProgrammingBeforeTraining)
{
    CEO ceo(nullptr);
    SoftwareEngineer se(&ceo);
    CustomerSupporter supporter(&se);

    testing::internal::CaptureStdout(); // Capture stdout
    supporter.Work(Task::HardProgramming);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("[SoftwareEngineer] Try to solve hard problem. But failed."), std::string::npos);
}

TEST(WorkerTest, HardProgrammingAfterTraining)
{
    CEO ceo(nullptr);
    SoftwareEngineer se(&ceo);
    CustomerSupporter supporter(&se);

    se.Train();

    testing::internal::CaptureStdout(); // Capture stdout
    supporter.Work(Task::HardProgramming);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("[SoftwareEngineer] Successfully solve hard problem"), std::string::npos);
}

TEST(WorkerTest, CEO)
{
    CEO ceo(nullptr);
    SoftwareEngineer se(&ceo);
    CustomerSupporter supporter(&se);

    testing::internal::CaptureStdout(); // Capture stdout
    supporter.Work(Task::MoneyIssue);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("[CEO] Resolve money issue."), std::string::npos);
}

TEST(WorkerTest, God)
{
    CEO ceo(nullptr);
    SoftwareEngineer se(&ceo);
    CustomerSupporter supporter(&se);

    God god(nullptr);
    ceo.ChangeSuccessor(&god);

    testing::internal::CaptureStdout(); // Capture stdout
    supporter.Work(Task::ImpossibleTask);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("[God] God can do anything"), std::string::npos);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

