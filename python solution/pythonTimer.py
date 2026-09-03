import time



class Timer:

    def __enter__(self):
        self.start_time = time.perf_counter()

    def __exit__(self, exc_type, exc_value, traceback):
            end_time = time.perf_counter()
            elapsed = end_time - self.start_time
            print(f"Executed in {elapsed:.4f} seconds")


def timer(func):
    def wrapper(*args, **kwargs):
        start_time = time.perf_counter()
        result = func(*args, **kwargs)
        end_time = time.perf_counter()
        elapsed = end_time - start_time
        print(f"Executed in {elapsed:.4f} seconds for sum {result}")
        return result
    return wrapper


@timer
def slow_function():
     return sum(i * i for i in range(10_000_000))


with Timer():
     print("hi")




