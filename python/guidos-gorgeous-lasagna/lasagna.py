"""Functions used in preparing Guido's gorgeous lasagna.

Learn about Guido, the creator of the Python language:
https://en.wikipedia.org/wiki/Guido_van_Rossum

This is a module docstring, used to describe the functionality
of a module and its functions and/or classes.
"""


EXPECTED_BAKE_TIME = 40
PREPARATION_TIME = 2


def bake_time_remaining(elapsed_bake_time):
    """Calculate the bake time remaining.

    :param elapsed_bake_time: int - baking time already elapsed.
    :return: int - remaining bake time (in minutes) derived from 'EXPECTED_BAKE_TIME'.

    Function that takes the actual minutes the lasagna has been in the oven as
    an argument and returns how many minutes the lasagna still needs to bake
    based on the `EXPECTED_BAKE_TIME`.
    """
    return EXPECTED_BAKE_TIME - elapsed_bake_time

# To avoid the use of magic numbers (see: https://en.wikipedia.org/wiki/Magic_number_(programming)), you should define a PREPARATION_TIME constant.
# You can do that on the line below the 'EXPECTED_BAKE_TIME' constant.
# This will make it easier to do calculations, and make changes to your code.
def preparation_time_in_minutes(layer_count):
    """this func Calculate the minute for preparation
    it takes one arg which is the number of layers in the lasagna 
    it uses the const PREPARATION_TIME which indicate how long each layer take
    """
    return layer_count * PREPARATION_TIME



def elapsed_time_in_minutes(number_of_layers, elapsed_bake_time):
    """this func Calculate how long has it been since we started cooking.
        it take 2 args one is the number of layers which we pass to preparation_time_in_minutes which give us how long total layers took.
        the other arg is elapsed_bake_time which we get from the elapsed_time_in_minutes func.
    """
    return preparation_time_in_minutes(number_of_layers) + elapsed_bake_time

    


#  (you can copy and then alter the one from bake_time_remaining.)
