from threadutility import ThreadRipper
from loguru import logger
from random import randint
import time


NUMBER_OF_JOBS = 100


def my_job(number: int, delay: int):
    time.sleep(delay)
    logger.info(f"{number}")
    return f"Input Number : {number} | Delay : {delay}"


if __name__ == "__main__":
    threading_helper: ThreadRipper = ThreadRipper(
        n_threads=10, thread_name_prefix="my_job"
    )

    for i in range(NUMBER_OF_JOBS):
        threading_helper.add_executables(my_job, i, randint(1, 5))

    threading_helper.start()

    logger.info(threading_helper.result)
