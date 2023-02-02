# This file only contains the implementation for the feeder.
# the given code has been removed

nextState = 1


def sync():
    while True:
        x = True
        if nextState == 1:
            for c in cats:
                if c.get_status() == State.EATING:
                    x = False
            if x:
                return
        elif nextState == 2:
            for m in mouse:
                if m.get_status() == State.EATING:
                    x = False
            if x:
                return


def main():
    global nextState
    while True:
        sync()
        if nextState == 1:
            for d in dogs:
                if d.get_status() != State.DEAD and d.get_status() != State.EATING:
                    d.goto_dishes()
            for c in cats:
                if c.get_status() != State.DEAD and c.get_status() != State.EATING:
                    c.goto_dishes()
            for m in mouse:
                if m.get_status() != State.DEAD and m.get_status() != State.EATING:
                    m.goto_dishes()
            nextState = 2
        elif nextState == 2:
            for c in cats:
                if c.get_status() != State.DEAD and c.get_status() != State.EATING:
                    c.goto_dishes()
            for m in mouse:
                if m.get_status() != State.DEAD and m.get_status() != State.EATING:
                    m.goto_dishes()
            nextState = 1


# here comes the main
