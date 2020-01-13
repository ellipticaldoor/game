#include "dialogueSystem.cpp"
#include <catch2/catch.hpp>

TEST_CASE("DialogueSystem") {
  DialogueSystem dialogue;

  DialogueGraph testDialogue = {
    {
      .author = "foo",
      .message = "hello",
    },
    {
      .author = "foo",
      .message = "are you here?",
      .next = {
        {
          .author = "player",
          .message = "yes",
          .next = {
            {
              .author = "foo",
              .message = "nice to know"
            }
          }
        },
        {
          .author = "player",
          .message = "no",
          .next = {
            {
              .author = "foo",
              .message = "where are you then?",
              .next = {
                {
                  .author = "player",
                  .message = "not here",
                },
                {
                  .author = "player",
                  .message = "I'm actually here",
                },
                {
                  .author = "player",
                  .message = "I don't know",
                },
              }
            },
          },
        },
      },
    },
    {
      .author = "foo",
      .message = "okay, goodbye",
    },
  };

  dialogue.loadDialogue(testDialogue);
  DialogueOptions options = dialogue.getOptions();

  REQUIRE(dialogue.isFinished == false);
  REQUIRE(dialogue.currentStepIndex == 0);
  REQUIRE(options.size() == 0);
  REQUIRE(dialogue.currentNode->author == testDialogue[0].author);
  REQUIRE(dialogue.currentNode->message == testDialogue[0].message);

  dialogue.nextNode();
  options = dialogue.getOptions();

  REQUIRE(dialogue.isFinished == false);
  REQUIRE(dialogue.currentStepIndex == 1);
  REQUIRE(dialogue.currentNode->author == testDialogue[1].author);
  REQUIRE(dialogue.currentNode->message == testDialogue[1].message);
  REQUIRE(options.size() == 2);
  REQUIRE(options[0] == testDialogue[1].next[0].message);
  REQUIRE(options[1] == testDialogue[1].next[1].message);

  dialogue.nextNode(1);
  options = dialogue.getOptions();

  REQUIRE(dialogue.isFinished == false);
  REQUIRE(dialogue.currentStepIndex == 1);
  REQUIRE(
    dialogue.currentNode->author == testDialogue[1].next[1].next[0].author);
  REQUIRE(
    dialogue.currentNode->message == testDialogue[1].next[1].next[0].message);
  REQUIRE(options.size() == 3);
  REQUIRE(options[0] == testDialogue[1].next[1].next[0].next[0].message);
  REQUIRE(options[1] == testDialogue[1].next[1].next[0].next[1].message);
  REQUIRE(options[2] == testDialogue[1].next[1].next[0].next[2].message);

  dialogue.nextNode(2);
  options = dialogue.getOptions();

  REQUIRE(dialogue.isFinished == false);
  REQUIRE(dialogue.currentStepIndex == 2);
  REQUIRE(options.size() == 0);
  REQUIRE(dialogue.currentNode->author == testDialogue[2].author);
  REQUIRE(dialogue.currentNode->message == testDialogue[2].message);

  dialogue.nextNode();

  REQUIRE(dialogue.isFinished == true);
}
