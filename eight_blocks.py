import matplotlib.pyplot as plt
import random

def h1(i,n):
    if i != n:
        return 1
    else:
        return 0

def h2(i,n): #used to assess the expect move and to calculate the distance
    return abs(i%3-n%3) + abs(i//3-n//3)

def expect_all(m,pos):
    sum_expect = 0
    for i in range(9):
        if m == 1:
            sum_expect += h1(i,pos[i])
        elif m == 2:
            sum_expect += h2(i,pos[i])
    return sum_expect

def list_to_num(pos):
    res = 0
    j = 1
    for i in range(9):
        res += j*pos[i]
        j *= 10
    return res

tree = []

def search_for_ans(m):
    pos = [0,1,2,3,4,5,6,7,8]
    random.shuffle(pos)
    sum_steps = 0
    tree.append(list_to_num(pos))
    return search_in_tree(m,pos,sum_steps)

def search_in_tree(m,pos,sum_steps):
    #tree.append(list_to_num(pos))
    pos_old = [m for m in pos]
    sum_expect = expect_all(m,pos)
    if sum_expect == 0:
        return sum_steps
    pos_to_move = []
    pos0 = 0
    expect_of_move = []
    for i in range(9):
        if pos[i] == 0:
            pos0 = i
            break
    for i in range(9):
        if h2(i,pos0) == 1:
            pos_to_move.append(i)
    for i in pos_to_move:
        pos_new = pos
        tmp = pos_new[pos0]
        pos_new[pos0] = pos_new[i]
        pos_new[i] = tmp
        expect_of_move.append(expect_all(m,pos_new))
    pos_min = 0 # the location of expect_min in pos_to_move
    expect_min = 100
    j = 0
    flag1 = 1
    for i in expect_of_move:
        if i <= expect_min:
            pos_tmp = [m for m in pos]
            tmp = pos[pos0]
            pos_tmp[pos0] = pos_tmp[pos_to_move[j]]
            pos_tmp[pos_to_move[j]] = tmp
            to_search = list_to_num(pos_tmp)
            '''flag = 0
            for k in tree:
                if k == to_search:
                    flag = 1
                    break
            if flag == 0:
                flag1 = 0
                expect_min = i
                pos_min = j '''
            if to_search not in tree:
                expect_min = i
                pos_min = j
        j += 1
    tmp = pos[pos0]
    pos[pos0] = pos[pos_to_move[pos_min]]
    pos[pos_to_move[pos_min]] = tmp
    flag = 0
    if flag1 == 0:
        tree.append(list_to_num(pos))
        sum_expect = expect_all(m,pos)
    else:
        return -1
    if sum_expect == 0:
        return sum_steps+1
    else:
        res = search_in_tree(m,pos,sum_steps+1)
        if res != -1:
            return res
        else:
            return search_in_tree(m,pos_old,sum_steps)

def main():
    expect_of_move1 = []
    sum_of_move = [0,0]
    sum_of_exp = []
    for i in range(1,100):
        sum_of_exp.append(i)
        sum_of_move[0] += search_for_ans(2)
        expect_of_move1.append(sum_of_move[0]/i)
    
    plt.scatter(sum_of_exp,expect_of_move1)
    plt.show()

if __name__ == '__main__':
    main()