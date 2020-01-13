#pragma once
#include <pch.hpp>

struct DialogueNode {
  std::string author;
  std::string message;
  std::vector<DialogueNode> next = {};

  // TODO: Add constructor
};

using DialogueGraph = std::vector<DialogueNode>;

DialogueGraph dialogueGraph01 = {
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
