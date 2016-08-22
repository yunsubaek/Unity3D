using UnityEngine;
using System.Collections;

public class Asset_ : MonoBehaviour
{
    AssetBundle m_cube;
    GameObject cube_obj;
    void Start()
    {
        m_cube = AssetBundle.LoadFromFile("C:\\Users\\yunsubaek_df\\Documents\\AssetBundleTest1\\AssetBundles\\Windows\\cube-bundle");

        cube_obj = (GameObject)m_cube.LoadAsset<GameObject>("Cube");
        GameObject.Instantiate(cube_obj,new Vector3(1,1,1),Quaternion.identity);
    }
}
