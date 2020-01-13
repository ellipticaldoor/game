#pragma once
#include "dialogueUtils.cpp"
#include <pch.hpp>

using DialogueOptions = std::vector<std::string>;

struct DialogueSystem {
  DialogueGraph *dialogue;
  DialogueNode *currentNode;
  unsigned long currentStepIndex = 0;
  bool isFinished = false;

  void loadDialogue(DialogueGraph &dialogueToLoad) {
    isFinished = false;
    dialogue = &dialogueToLoad;
    currentNode = &dialogue->at(currentStepIndex);
  }

  void nextStep() {
    bool canGoToNextStep = currentStepIndex < dialogue->size() - 1;

    if (canGoToNextStep) {
      currentStepIndex += 1;
      currentNode = &dialogue->at(currentStepIndex);
    } else {
      isFinished = true;
    }
  }

  void nextNode(const unsigned long &optionSelection = 0) {
    bool availableNextNode = currentNode->next.size() > 0;

    if (availableNextNode) {
      currentNode = &currentNode->next[optionSelection];
      if (currentNode->author == "player") {
        nextNode();
      }
    } else {
      nextStep();
    }
  }

  DialogueOptions getOptions() {
    DialogueOptions options;

    for (DialogueNode &node : currentNode->next) {
      options.push_back(node.message);
    }

    return options;
  }
};
