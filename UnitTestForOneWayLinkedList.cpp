#include "CppUnitTest.h"
#include "/Users/varka/source/repos/AlgoLaba1_OneWayLinkedList/L1List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForOneWayLinkedList
{
	TEST_CLASS(UnitTestForOneWayLinkedList)
	{
	public:
		TEST_METHOD(IsEmptyListWhenEmpty)
		{
			L1List List;
			Assert::AreEqual(List.isEmpty(), true);
		}
		TEST_METHOD(IsEmptyListWhenNotEmpty)
		{
			L1List List;
			List.push_back((string)"bla");
			Assert::AreEqual(List.isEmpty(), false);
		}
		TEST_METHOD(ListSizeZero)
		{
			L1List List;
			Assert::AreEqual(List.get_size(), (size_t)0);
		}
		TEST_METHOD(ListSizeNotZero)
		{
			L1List List;
			List.push_back("bla");
			List.push_back("ha");
			List.push_front("hehe");
			Assert::AreEqual(List.get_size(), (size_t)3);
		}
		TEST_METHOD(PushBackOneElement)
		{
			L1List List;
			List.push_back("bla");
			Assert::AreEqual(List.get_head()->get_data(), (string)"bla");
		}
		TEST_METHOD(PushBackElements)
		{
			L1List List;
			List.push_back("bla");
			List.push_back("car");
			Assert::AreEqual(List.get_data(), (string)"car");
		}
		TEST_METHOD(PopBackFromEmptyList)
		{
			L1List List;
			try
			{
				List.pop_back();
			}
			catch (const exception& message)
			{
				Assert::AreEqual(message.what(), "The List is empty");
			}
		}
		TEST_METHOD(PopBackFromListWithOneElement)
		{
			L1List List;
			List.push_back("hello");
			List.pop_back();
			Assert::AreEqual(List.isEmpty(), true);
		}
		TEST_METHOD(PopBackFromList)
		{
			L1List List;
			List.push_back("!!!");
			List.push_back("hello");
			List.push_back("bro");
			List.pop_back();
			Assert::AreEqual(List.get_data(), (string)"hello");
		}
		TEST_METHOD(PushFrontInEmptyList)
		{
			L1List List;
			List.push_front("hey");
			Assert::AreEqual(List.get_data(), (string)"hey");
			Assert::AreEqual(List.get_next() == nullptr, true);
			Assert::AreEqual(List.get_head() == List.get_tail(), true);
		}
		TEST_METHOD(PushFrontInNotEmptyList)
		{
			L1List List;
			List.push_front("a good day");
			List.push_front("i wish you");
			List.push_front("hey"); 
			Assert::AreEqual(List.get_data(), (string)"hey");
		}
		TEST_METHOD(PopFrontFromEmptyList)
		{
			L1List List;
			try
			{
				List.pop_front();
			}
			catch (const exception & message)
			{
				Assert::AreEqual(message.what(), "The List is empty");
			}
		}
		TEST_METHOD(PopFrontFromList)
		{
			L1List List;
			List.push_front("a good day");
			List.push_front("i wish you");
			List.push_front("hey");
			List.pop_front();
			Assert::AreEqual(List.get_data(), (string)"i wish you");
		}
		TEST_METHOD(PopFrontFromOneElementList)
		{
			L1List List;
			List.push_front("hey");
			List.pop_front();
			Assert::AreEqual(List.isEmpty(), true);
		}
		TEST_METHOD(AtInEmptyList)
		{
			L1List List;
			try
			{
				List.at(0);
			}
			catch (const exception & message)
			{
				Assert::AreEqual(message.what(), "Invalid index");
			}
		}
		TEST_METHOD(AtInListWhenPushFronted)
		{
			L1List List;
			List.push_front("a good day");
			List.push_front("i wish you");
			List.push_front("hey");
			Assert::AreEqual(List.at(2)->get_data(), (string)"a good day");
			Assert::AreEqual(List.at(1)->get_data(), (string)"i wish you");
			Assert::AreEqual(List.at(0)->get_data(), (string)"hey");
		}
		TEST_METHOD(AtInListWhenPushBacked)
		{
			L1List List;
			List.push_back("hey");
			List.push_back("i wish you");
			List.push_back("a good day");
			Assert::AreEqual(List.at(2)->get_data(), (string)"a good day");
			Assert::AreEqual(List.at(1)->get_data(), (string)"i wish you");
			Assert::AreEqual(List.at(0)->get_data(), (string)"hey");
		}
		TEST_METHOD(AtInListWhenPushed)
		{
			L1List List;
			List.push_back("i wish you");
			List.push_front("hey");
			List.push_back("a good day");
			Assert::AreEqual(List.at(2)->get_data(), (string)"a good day");
			Assert::AreEqual(List.at(1)->get_data(), (string)"i wish you");
			Assert::AreEqual(List.at(0)->get_data(), (string)"hey");
		}
		TEST_METHOD(InsertToListBegin)
		{
			L1List List;
			List.push_front("khe");
			List.push_back("is this a coronavirus???");
			List.push_back("we are going to die");
			List.insert("Oh no!", 0);
			Assert::AreEqual(List.at(0)->get_data(), (string)"Oh no!");
		}
		TEST_METHOD(InsertToListEnd)
		{
			L1List List;
			List.push_front("khe");
			List.push_back("is this a coronavirus???");
			List.push_back("we are going to die");
			List.insert("Oh no!", 3);
			Assert::AreEqual(List.at(3)->get_data(), (string)"Oh no!");
		}
		TEST_METHOD(InsertToListMiddle)
		{
			L1List List;
			List.push_front("khe");
			List.push_back("is this a coronavirus???");
			List.push_back("we are going to die");
			List.insert("Oh no!", 2);
			Assert::AreEqual(List.at(2)->get_data(), (string)"Oh no!");
		}
		TEST_METHOD(InsertToListInvalidIndex)
		{
			L1List List;
			List.push_front("khe");
			try
			{
				List.insert("bla", 2);
			}
			catch (const exception & message)
			{
				Assert::AreEqual(message.what(), "Invalid index");
			}
		}
		TEST_METHOD(RemoveFromListInvalidIndex)
		{
			L1List List;
			List.push_front("khe");
			try
			{
				List.remove(2);
			}
			catch (const exception & message)
			{
				Assert::AreEqual(message.what(), "Invalid index");
			}
		}
		TEST_METHOD(RemoveFromOneElementList)
		{
			L1List List;
			List.push_front("khe");
			List.remove(0);
			Assert::AreEqual(List.isEmpty(), true);
		}
		TEST_METHOD(RemoveFromList)
		{
			L1List List;
			List.push_front("khe");
			List.push_back("is this a coronavirus???");
			List.push_back("we are going to die");
			List.insert("Oh no!", 2);
			List.remove(2);
			Assert::AreEqual(List.at(2)->get_data(), (string)"we are going to die");
		}
		TEST_METHOD(RemoveFromListEnd)
		{
			L1List List;
			List.push_front("khe");
			List.push_back("is this a coronavirus???");
			List.push_back("we are going to die");
			List.insert("Oh no!", 2);
			List.remove(3);
			Assert::AreEqual(List.at(2) == List.get_tail(), true);
		}
		TEST_METHOD(RemoveFromListBegin)
		{
			L1List List;
			List.push_front("khe");
			List.push_back("is this a coronavirus???");
			List.push_back("we are going to die");
			List.insert("Oh no!", 2);
			List.remove(0);
			Assert::AreEqual(List.at(0)->get_data(), (string)"is this a coronavirus???");
		}
		TEST_METHOD(SetInListBegin)
		{
			L1List List;
			List.push_front("khe");
			List.push_back("is this a coronavirus???");
			List.push_back("we are going to die");
			List.set(0, "apchi!");
			Assert::AreEqual(List.at(0)->get_data(), (string)"apchi!");
		}
		TEST_METHOD(SetInListEnd)
		{
			L1List List;
			List.push_front("khe");
			List.push_back("is this a coronavirus???");
			List.push_back("we are going to die");
			List.set(2, "apchi!");
			Assert::AreEqual(List.at(2)->get_data(), (string)"apchi!");
		}
		TEST_METHOD(SetInEmptyList)
		{
			L1List List;
			try
			{
				List.set(0, "apchi!");
			}
			catch (const exception & message)
			{
				Assert::AreEqual(message.what(), "Invalid index");
			}
		}
		TEST_METHOD(SetInListInvalidIndex)
		{
			L1List List;
			List.push_back("khe-khe");
			try
			{
				List.set(1, "apchi!");
			}
			catch (const exception & message)
			{
				Assert::AreEqual(message.what(), "Invalid index");
			}
		}
		TEST_METHOD(SetInList)
		{
			L1List List;
			List.push_front("khe");
			List.push_back("is this a coronavirus???");
			List.push_back("we are going to die");
			List.set(1, "apchi!");
			Assert::AreEqual(List.at(1)->get_data(), (string)"apchi!");
		}
		TEST_METHOD(ClearEmptyList)
		{
			L1List List;
			try
			{
				List.clear();
			}
			catch (const exception & message)
			{
				Assert::AreEqual(message.what(), "The List is empty");
			}
		}
		TEST_METHOD(ClearList)
		{
			L1List List;
			List.push_front("khe");
			List.push_back("is this a coronavirus???");
			List.push_back("we are going to die");
			List.set(1, "apchi!");
			List.clear();
			Assert::AreEqual(List.isEmpty(), true);
			Assert::AreEqual(List.get_head() == nullptr, true);
			Assert::AreEqual(List.get_tail() == nullptr, true);
			Assert::AreEqual(List.get_cur() == nullptr, true);
			Assert::AreEqual(List.get_size(), (size_t)0);
		}
		TEST_METHOD(PushFrontAList)
		{
			L1List one, two;
			one.push_back("Hello");
			one.push_back("my name is Barbara");
			two.push_back("I'm to become a programmer");
			two.push_back("And this is good");
			two.push_back("What do you think?");
			two.push_front(&one);
			Assert::AreEqual(two.at(1)->get_data(), (string)"my name is Barbara");
			Assert::AreEqual(one.get_size(), (size_t)2);
			Assert::AreEqual(two.get_size(), (size_t)5);
		}
		TEST_METHOD(PushFrontAListChangeOne)
		{
			L1List one, two;
			one.push_back("Hello");
			one.push_back("my name is Barbara");
			two.push_back("I'm to become a programmer");
			two.push_back("And this is good");
			two.push_back("What do you think?");
			two.push_front(&one);
			one.pop_front();
			Assert::AreEqual(two.at(0)->get_data(), (string)"Hello");
			Assert::AreEqual(one.get_size(), (size_t)1);
			Assert::AreEqual(two.get_size(), (size_t)5);
		}
		TEST_METHOD(PushFrontAListClearOne)
		{
			L1List one, two;
			one.push_back("Hello");
			one.push_back("my name is Barbara");
			two.push_back("I'm to become a programmer");
			two.push_back("And this is good");
			two.push_back("What do you think?");
			two.push_front(&one);
			one.clear();
			Assert::AreEqual(two.at(0)->get_data(), (string)"Hello");
			Assert::AreEqual(one.get_size(), (size_t)0);
			Assert::AreEqual(two.get_size(), (size_t)5);
		}
		TEST_METHOD(PushFrontAListClearTwo)
		{
			L1List one, two;
			one.push_back("Hello");
			one.push_back("my name is Barbara");
			two.push_back("I'm to become a programmer");
			two.push_back("And this is good");
			two.push_back("What do you think?");
			two.push_front(&one);
			two.clear();
			Assert::AreEqual(two.isEmpty(), true);
			Assert::AreEqual(one.get_size(), (size_t)2);
			Assert::AreEqual(one.at(0)->get_data(), (string)"Hello");
		}
		TEST_METHOD(PushFrontAListChangeTwo)
		{
			L1List one, two;
			one.push_back("Hello");
			one.push_back("my name is Barbara");
			two.push_back("I'm to become a programmer");
			two.push_back("And this is good");
			two.push_back("What do you think?");
			two.push_front(&one);
			two.set(1, "I'm Bond. James Bond.");
			Assert::AreEqual(one.at(1)->get_data(), (string)"my name is Barbara");
			Assert::AreEqual(two.at(1)->get_data(), (string)"I'm Bond. James Bond.");
		}
		TEST_METHOD(PushFrontAListClearBoth)
		{
			L1List one, two;
			one.push_back("Hello");
			one.push_back("my name is Barbara");
			two.push_back("I'm to become a programmer");
			two.push_back("And this is good");
			two.push_back("What do you think?");
			two.push_front(&one);
			one.clear();
			two.clear();
			Assert::AreEqual(two.isEmpty(), true);
			Assert::AreEqual(one.isEmpty(), true);
		}
		TEST_METHOD(PushFrontAListSecondEmpty)
		{
			L1List one, two;
			one.push_back("maybe"); // 0
			one.push_back("today"); // 1
			one.push_back("is"); // 2
			one.push_back("a very"); // 3
			one.push_back("good"); // 4
			one.push_back("day?"); // 5
			two.push_front(&one);
			Assert::AreEqual(two.at(0)->get_data(), (string)"maybe");
			Assert::AreEqual(two.at(1)->get_data(), (string)"today");
			Assert::AreEqual(two.at(2)->get_data(), (string)"is");
			Assert::AreEqual(two.at(3)->get_data(), (string)"a very");
			Assert::AreEqual(two.at(4)->get_data(), (string)"good");
			Assert::AreEqual(two.at(5)->get_data(), (string)"day?");
			Assert::AreEqual(two.get_size(), (size_t)6);
		}
	};
}
