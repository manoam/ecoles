<?php

/**
 * @file
 * class UserUserWrapper
 */
class UserUserWrapper extends WdUserWrapper {

    protected $entity_type = 'user';
    private static $bundle = 'user';

    /**
     * Create a new user user.
     *
     * @param array $values
     * @param string $language
     * @return UserUserWrapper
     */
    public static function create($values = array(), $language = LANGUAGE_NONE) {
        $values += array('entity_type' => 'user', 'bundle' => self::$bundle, 'type' => self::$bundle);
        $entity_wrapper = parent::create($values, $language);
        return new UserUserWrapper($entity_wrapper->value());
    }

    public static function getAllRoles() {

        $roles = array();

        $query = "SELECT rid, name FROM role";

        $result = db_query($query);

        while ($record = $result->fetchAssoc()) {
            $roles[$record['rid']] = $record['name'];
        }

        return $roles;
    }

    public static function getAllUsers() {

        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'user');
        $output = array();
        $results = $query->execute();

        if (isset($results['user'])) {

            $userids = array_keys($results['user']);
            $users = user_load_multiple($userids);

            foreach ($users as $user) {
                
                $user_entity = new UserUserWrapper($user->uid);
                if($user->uid != 0){
                    $output[$user->uid] = $user_entity->getName() .' ('.$user_entity->getNom().')';
                }
            }
        }

        return $output;
    }

    /**
     * Sets field_nom
     *
     * @param $value
     *
     * @return $this
     */
    public function setNom($value, $format = NULL) {
        $this->setText('field_nom', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_nom
     *
     * @return mixed
     */
    public function getNom($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_nom', $format, $markup_format);
    }

    /**
     * Sets field_tel
     *
     * @param $value
     *
     * @return $this
     */
    public function setTel($value, $format = NULL) {
        $this->setText('field_tel', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_tel
     *
     * @return mixed
     */
    public function getTel($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_tel', $format, $markup_format);
    }

    /**
     * Sets field_adress
     *
     * @param $value
     *
     * @return $this
     */
    public function setAdress($value, $format = NULL) {
        $this->setText('field_adress', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_adress
     *
     * @return mixed
     */
    public function getAdress($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_adress', $format, $markup_format);
    }

    /**
     * Sets field_image
     *
     * @param $value
     *
     * @return $this
     */
    public function setImage($value) {
        $this->set('field_image', $value);
        return $this;
    }

    /**
     * Retrieves field_image
     *
     * @return mixed
     */
    public function getImage() {
        return $this->get('field_image');
    }

    /**
     * Retrieves field_image as an HTML <img> tag
     *
     * @param string $image_style
     *   (optional) Image style for the HTML
     * @param array $options
     *   (optional) options to pass to the theme function. If you want to add
     *   attributes, you can do that under the attributes key of this array.
     *
     * @return string
     */
    public function getImageHtml($image_style = NULL, $options = array()) {
        $image = $this->get('field_image');
        if (!empty($image)) {
            $options += array(
                'path' => $image['uri'],
            );
            if (!is_null($image_style)) {
                $options['style_name'] = $image_style;
                return theme('image_style', $options);
            } else {
                return theme('image', $options);
            }
        }
        return NULL;
    }

    /**
     * Retrieves field_image as a URL
     *
     * @param string $image_style
     *   (optional) Image style for the URL
     * @param bool $absolute
     *   Whether to return an absolute URL or not
     *
     * @return string
     */
    public function getImageUrl($image_style = NULL) {
        $image = $this->get('field_image');
        if (!empty($image)) {
            if (!is_null($image_style)) {
                return image_style_url($image_style, $image['uri']);
            } else {
                return url(file_create_url($image['uri']));
            }
        }
        return NULL;
    }

    /**
     * Sets field_sex
     *
     * @param $value
     *
     * @return $this
     */
    public function setSex($value) {
        $this->set('field_sex', $value);
        return $this;
    }

    /**
     * Retrieves field_sex
     *
     * @return mixed
     */
    public function getSex() {
        return $this->get('field_sex');
    }

    /**
     * Sets field_date_naiss
     *
     * @param $value
     *
     * @return $this
     */
    public function setDateNaiss($value) {
        $this->set('field_date_naiss', $value);
        return $this;
    }

    /**
     * Retrieves field_date_naiss
     *
     * @return mixed
     */
    public function getDateNaiss() {
        return $this->get('field_date_naiss');
    }

    /**
     * Sets field_biographie
     *
     * @param $value
     *
     * @return $this
     */
    public function setBiographie($value, $format = NULL) {
        $this->setText('field_biographie', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_biographie
     *
     * @return mixed
     */
    public function getBiographie($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_biographie', $format, $markup_format);
    }

}
