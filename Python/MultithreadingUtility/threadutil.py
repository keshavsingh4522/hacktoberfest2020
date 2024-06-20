from typing import Callable, Any
from functools import partial
import concurrent.futures
from loguru import logger # pip install -q -U loguru


class ThreadRipper(object):
    def __init__(self, n_threads: int = 4, thread_name_prefix: str = "TRip") -> None:
        """Executes a series of partial functions in multithreading.

        Args:
            n_threads (int): number of threads
            thread_name_prefix (str, optional): thread prefix name. Defaults to "TRip".
        Usage:
            _tr = ThreadRipper(60)
            for i in range(500):
                _tr.add_executables(callable_function, d=i, i=1)
            _tr.start()
            print(_tr.result) # to get the collated result

        """

        self.__thread_name_prefix = thread_name_prefix
        self.__partials = []
        self.__thread_count = n_threads
        self.__futures = []

    def add_executables(self, func: Callable, *fargs: Any, **fkwargs: Any):
        self.__partials.append(partial(func, *fargs, **fkwargs))

    def start(self):
        logger.info(
            f"Dispatching ThreadPoolExecutor with {self.__thread_count} threads(s)"
        )
        with concurrent.futures.ThreadPoolExecutor(
            self.__thread_count, thread_name_prefix=self.__thread_name_prefix
        ) as executor:
            _res = []
            for executable in self.__partials:
                _res.append(executor.submit(executable))
            executor.shutdown(wait=False)
            self.__futures = [i.result() for i in _res]

    @property
    def result(self):
        try:
            return self.__futures
        finally:
            self.__partials = []
            self.__futures = []
