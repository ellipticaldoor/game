#pragma once
#include "dialogueUtils.cpp"
#include "helpers.cpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// // TODO: Add reserved characters !$%*(){}.,
std::vector<std::string> reserved = {
  "!", "?", "$", "<", "^", "*", "(", ")", "{", "}", ":", ";", ",", ".", " - ",
};
std::vector<std::string> validStart = { "#", "@", ">", "/" };

std::string getAuthorAndMessage(const std::string &line) {
  // TODO: Check @ and - exists
  // TODO: Check blank space after @ and before -
  // TODO: Return author and message
  return "";
}

static DialogueGraph parseScript(const std::string &script) {
  auto scriptStream = std::istringstream(script);
  DialogueGraph dialogueGraph = {};

  std::string line;
  while (std::getline(scriptStream, line)) {
    if (line.size() == 0) continue;
    auto firstCharacter = line.substr(0, 1);

    auto isValidStart =
      std::find(validStart.begin(), validStart.end(), firstCharacter);

    if ((isValidStart == validStart.end())) continue;

    if (firstCharacter != "@") continue;

    getAuthorAndMessage(line);
    DialogueNode node = { "author", "message" };
    // TODO: Instantiate node inside emplace_back to avoid a copy
    dialogueGraph.emplace_back(node);
  }

  return dialogueGraph;
}

static DialogueGraph loadScriptFile(const std::string &scriptSource) {
  auto script = readTextFile(scriptSource);
  return parseScript(script);
}
