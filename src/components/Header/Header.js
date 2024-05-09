import {View, Text, StyleSheet} from 'react-native';
import React from 'react';
import Location from '../Location/Location';
import {TouchableOpacity} from 'react-native-gesture-handler';
import {Image} from 'react-native';
import Icon from 'react-native-vector-icons/Feather';

const Header = () => {
  return (
    <>
      <View style={styles.headerContainer}>
        <View style={styles.headerItem}>
          <TouchableOpacity
            style={{
              elevation: 15,
            }}>
            <Image
              source={{
                uri: 'https://t4.ftcdn.net/jpg/03/64/21/11/360_F_364211147_1qgLVxv1Tcq0Ohz3FawUfrtONzz8nq3e.jpg',
              }}
              style={styles.profileImage}
            />
          </TouchableOpacity>
          <View style={styles.textName}>
            <Text
              style={{
                fontSize: 12,
                color: '#4f5d75',
              }}>
              Hey 👋. Welcome 🎉
            </Text>
            <Text
              style={{
                fontSize: 16,
                color: '#4f5d75',
                fontWeight: '600',
              }}>
              Fahad Mahamood
            </Text>
          </View>
        </View>
        <Icon
          style={{
            marginRight: 5,
          }}
          size={22}
          color="#4f5d75"
          name="bell"
        />
      </View>
      <Location />
    </>
  );
};

const styles = StyleSheet.create({
  headerContainer: {
    flexDirection: 'row',
    paddingHorizontal: 15,
    paddingVertical: 10,
    backgroundColor: 'white',
    justifyContent: 'space-between',
    alignItems: 'center',
    // position: 'fixed',
  },
  headerItem: {
    flexDirection: 'row',
    // backgroundColor: '#355efc',
  },
  textName: {
    marginLeft: 10,
  },
  profileImage: {
    height: 36,
    width: 36,
    borderRadius: 50,
    evaluation: 15,
  },
});

export default Header;
