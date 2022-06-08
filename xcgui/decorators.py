import functools
from xcgui._xcgui import CallUiThread


class RunUiThread:
    def __call__(self, func):
        self.func = func

        @functools.wraps(func)
        def objCall(*args, **kwargs):
            CallUiThread(self.func, *args, **kwargs)

        return objCall
