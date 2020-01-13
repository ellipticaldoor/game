#pragma once
#include "colors.cpp"
#include "dialogueSystem.cpp"
#include "enumerate.hpp"
#include "fonts.cpp"
#include "sdl.cpp"
#include "sizes.cpp"
#include "text.cpp"
#include "textures.cpp"
#include <pch.hpp>

struct Dialogue {
  DialogueSystem dialogue;
  Text authorText = { fonts.largeItalic };
  Text messageText = { fonts.mediumBold };
  std::vector<Text> optionsText = {};
  unsigned long currentOption = 0;

  Dialogue() {
    dialogue.loadDialogue(dialogueGraph01);
    setupOptions();
  }

  void setupOptions() {
    optionsText.clear();
    DialogueOptions options = dialogue.getOptions();
    optionsText.reserve(options.size());

    for (const auto [index, option] : enumerate(options)) {
      std::string optionText = index == currentOption ? "> " + option : option;
      optionsText.emplace_back(fonts.medium, optionText);
    }
  }

  void acceptOption() {
    dialogue.nextNode(currentOption);
    currentOption = 0;
    setupOptions();
  }

  void selectNextOption() {
    if (currentOption < optionsText.size() - 1) {
      currentOption += 1;
    } else {
      currentOption = 0;
    }
    setupOptions();
  }

  void selectPreviousOption() {
    if (currentOption != 0) {
      currentOption -= 1;
    } else {
      currentOption = optionsText.size() - 1;
    }
    setupOptions();
  }

  void render() {
    int vTop = sdl.windowHeight / 2;
    renderTexture(
      textures.dialogueBox, 0, vTop, sdl.windowWidth, sdl.windowHeight / 2);

    int hPadding = size.medium;
    int vPadding = vTop + size.medium;
    authorText.render(dialogue.currentNode->author, hPadding, vPadding);

    int messageY = vPadding + authorText.h + size.medium;
    messageText.render(dialogue.currentNode->message, hPadding, messageY);

    for (const auto [index, option] : enumerate(optionsText)) {
      int optionYPadding =
        index == 0 ? 0 : (optionsText[index - 1].h + size.small) * index;
      int optionY = messageY + messageText.h + size.medium + optionYPadding;
      option.render(option.text, hPadding, optionY);
    }
  }
};
