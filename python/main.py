""" Example python module. """

import argparse

import gtsam

import cplayground

# pylint: disable = no-member


def greet():
    """
    Call the wrapped Greeting code so it can say Hello and Goodbye.
    """
    v_doble = [1.5,2.0,3.5,4.0]
    greeter = cplayground.PybindTest(1.5, v_doble)
    greeter.print_vec()
    return greeter.sayHello()


def parse_arguments():
    parser = argparse.ArgumentParser("Main runner for GTSAM-wrapped code")
    parser.add_argument("command",
                        help="The function to execute \
                            (e.g. 'meaning_of_everything', 'create_special_2d_pose', 'greet')")
    return parser.parse_args()


if __name__ == "__main__":
    func_map = {
        'greet': greet
    }
    args = parse_arguments()
    func = func_map.get(args.command, "greet")
    print(func())
