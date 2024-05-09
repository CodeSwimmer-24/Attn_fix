import {View, Text, Image} from 'react-native';
import React from 'react';
import {TouchableOpacity} from 'react-native-gesture-handler';
import doctor from '../../../assets/icons/doctor.png';

const HomeCategories = () => {
  return (
    <View
      style={{
        justifyContent: 'center',
        alignItems: 'center',
        marginTop: 20,
        width: '100%',
      }}>
      <View
        style={{
          width: '90%',
          flexDirection: 'row',
          justifyContent: 'space-between',
          alignItems: 'center',
          padding: 5,
        }}>
        <Text
          style={{
            fontSize: 16,
            fontWeight: '400',
            color: '#4f5d75',
          }}>
          All Categories
        </Text>
        <TouchableOpacity>
          <Text
            style={{
              fontSize: 14,
              fontWeight: '300',
              color: '#ef8354',
              fontWeight: 'bold',
            }}>
            See All
          </Text>
        </TouchableOpacity>
      </View>
      <View
        style={{
          flexDirection: 'row',
          justifyContent: 'space-evenly',
          alignItems: 'center',
          width: '100%',
          marginTop: 5,
        }}>
        <View
          style={{
            display: 'flex',
            alignItems: 'center',
          }}>
          <TouchableOpacity
            style={{
              padding: 8,
              backgroundColor: '#4f5d751a',
              borderRadius: 50,
            }}>
            <View>
              <Image
                source={doctor}
                style={{
                  width: 35,
                  height: 35,
                }}
              />
            </View>
          </TouchableOpacity>
          <Text
            style={{
              color: '#4f5d75',
            }}>
            Doctor
          </Text>
        </View>
        <TouchableOpacity
          style={{
            padding: 8,
            backgroundColor: '#4f5d751a',
            borderRadius: 50,
          }}>
          <Image
            source={doctor}
            style={{
              width: 35,
              height: 35,
            }}
          />
        </TouchableOpacity>
        <TouchableOpacity
          style={{
            padding: 8,
            backgroundColor: '#4f5d751a',
            borderRadius: 50,
          }}>
          <Image
            source={doctor}
            style={{
              width: 35,
              height: 35,
            }}
          />
        </TouchableOpacity>
        <TouchableOpacity
          style={{
            padding: 8,
            backgroundColor: '#4f5d751a',
            borderRadius: 50,
          }}>
          <Image
            source={doctor}
            style={{
              width: 35,
              height: 35,
            }}
          />
        </TouchableOpacity>
      </View>
    </View>
  );
};

export default HomeCategories;
