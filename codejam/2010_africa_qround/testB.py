import os;

fin = open("B-small.in");

# number of line
nol = fin.readline();

cnt = 0;

for str_line in fin:
    cnt = cnt + 1;
    str_line = str_line.replace('\n', '');
    str_line = str_line.replace('\r', '');
    str_buf = str_line.split(' ');

#    str_buf.sort();

    str_result = ""
    for word in str_buf:
        str_result = "%s %s" % (word, str_result);

# commented out --------------- str_result =
    print "Case #%d: %s" %(cnt, str_result);


