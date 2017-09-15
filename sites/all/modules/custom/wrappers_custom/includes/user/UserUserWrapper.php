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
        
        $roles  = array();
        
        $query  = "SELECT rid, name FROM role";
        
        $result = db_query($query);
        
        while ($record = $result->fetchAssoc()) {
            $roles[$record['rid']] = $record['name'];
        }
        
        return $roles;
    }
}
