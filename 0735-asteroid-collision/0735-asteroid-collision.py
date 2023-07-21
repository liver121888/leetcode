class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        final_state = []
        store = True
        for a in asteroids:
            store = True
            if not final_state:
                final_state.append(a)
                continue
                
            if a < final_state[-1] and a / final_state[-1] < 0:
                while final_state and abs(a) > abs(final_state[-1]) and a / final_state[-1] < 0 :
                    final_state.pop()
                else:
                    if not final_state:
                        final_state.append(a)
                        continue                    
                    if a < final_state[-1] and a / final_state[-1] < 0:
                        if abs(a) == abs(final_state[-1]):
                            final_state.pop()
                            store = False
                        else:
                            store = False
                    else:
                        store = True                    
                
                if store:
                    final_state.append(a)
            else:
                final_state.append(a)
        return final_state