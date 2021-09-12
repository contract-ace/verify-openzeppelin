import os
import re
import sys

# SmartACE and Scribble use different versions of Solidity. This script
# postprocesses the output of Scribble so that it can be consumed by SmartACE.
# This script is specialized to the three contracts in the Verify-OpenZeppelin
# study, and may not work for other contracts.

PRAGMA_PRE  = "pragma solidity 0.8.6;"
PRAGMA_POST = ""

VIRTUAL_PRE  = "virtual "
VIRTUAL_POST = ""

UNCHECKED_PRE  = "unchecked "
UNCHECKED_POST = ""

CTOR_PRE  = r"(constructor\([^)]*\))"
CTOR_POST = r"\1 public"

OVERRIDE_PRE  = "override "
OVERRIDE_POST = ""

IMMUTABLE_PRE  = "immutable "
IMMUTABLE_POST = ""

FALLBACK_PRE  = "fallback()"
FALLBACK_POST = "function()"

def postprocess_scribble(pre_name, post_name):
    with open(pre_name, "r") as pre_file:
        text = pre_file.read()
        text = text.replace(PRAGMA_PRE, PRAGMA_POST)
        text = text.replace(VIRTUAL_PRE, VIRTUAL_POST)
        text = text.replace(UNCHECKED_PRE, UNCHECKED_POST)
        text = re.sub(CTOR_PRE, CTOR_POST, text, re.M)
        text = text.replace(OVERRIDE_PRE, OVERRIDE_POST)
        text = text.replace(IMMUTABLE_PRE, IMMUTABLE_POST)
        text = text.replace(FALLBACK_PRE, FALLBACK_POST)
        with open(post_name, "w+") as post_file:
            post_file.write(text)

def main():
    assert(len(sys.argv) == 3)
    pre_name = sys.argv[1]
    post_name = sys.argv[2]
    assert(not os.path.isfile(post_name))
    postprocess_scribble(pre_name, post_name)

if __name__ == '__main__':
    main()

