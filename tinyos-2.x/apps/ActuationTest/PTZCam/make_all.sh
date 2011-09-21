# IP: 172.17.4.XX (XX = 170 + Tag_ID - 1)
# Node 15: Tag ID - 16
make micaz reinstall,15 eprb,172.17.4.185 &
sleep 2
# Node 16: Tag ID - 11
make micaz reinstall,16 eprb,172.17.4.180 &
sleep 2
# Node 17: Tag ID - 6
make micaz reinstall,17 eprb,172.17.4.175 &
sleep 2
# Node 18: Tag ID - 1
make micaz reinstall,18 eprb,172.17.4.170 &
sleep 2
# Node 11: Tag ID - 17
make micaz reinstall,11 eprb,172.17.4.186 &
sleep 2
# Node 12: Tag ID - 12
make micaz reinstall,12 eprb,172.17.4.181 &
sleep 2
# Node 13: Tag ID - 2
make micaz reinstall,13 eprb,172.17.4.171 &
sleep 2
# Node 8: Tag ID -8
make micaz reinstall,8 eprb,172.17.4.177 &
