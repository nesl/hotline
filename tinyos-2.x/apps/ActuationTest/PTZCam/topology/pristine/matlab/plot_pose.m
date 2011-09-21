xy = load('camera_pose_9_loc.dat');
A = load('camera_pose_9_adj.dat');
gplot(A, xy)
text(xy(:,1),xy(:,2),int2str(r'))
